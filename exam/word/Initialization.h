#ifndef INITIALIZATION_H
#define INITIALIZATION_H

#include "CommandInterface.h"

#include <memory>
#include <string>




#include <map>
#include <memory>
#include <string>
#include <vector>
#include <sstream>

#include "TextTransform.h"

using TextTransformPtr = std::shared_ptr<TextTransform>;
using Command = std::pair<std::string, TextTransformPtr>;

class BetterCommandInterface : public CommandInterface{
private:
    std::map<std::string, std::shared_ptr<TextTransform> > commandTransforms;
    std::string& text;
static std::string savedCut;

    class ToUpperTransform : public TextTransform {
    public:
        virtual void invokeOn(std::string &text, int startIndex, int endIndex) override {
            for (int i = startIndex; i < endIndex; i++) {
                text[i] = toupper(text[i]);
            }
        }
    };

    class PasteTransform : public TextTransform {
    public:
        virtual void invokeOn(std::string &text, int startIndex, int endIndex) override {
            text.replace(startIndex, endIndex - startIndex, savedCut);
        }
    };
    class CutTransform : public TextTransform {
        public:
            virtual void invokeOn(std::string& text, int startIndex, int endIndex) override {
                std::string cut = text.substr(startIndex, endIndex-startIndex);
                text.erase(startIndex, endIndex-startIndex);
                savedCut = cut;
            }
        };



public:

    BetterCommandInterface(std::string& text) : CommandInterface(text), text{text} {
        this->savedCut = "";
    }

//    void init() {
//        this->commandTransforms.clear();
//        for (std::pair<std::string, std::shared_ptr<TextTransform> > p : this->initCommands()) {
//            commandTransforms[p.first] = p.second;
//        }
//    }
//
//    void handleInput(std::string input) {
//        std::istringstream parseStream(input);
//
//        std::string commandName;
//        int startInd, endInd;
//
//        parseStream >> commandName >> startInd >> endInd;
//
//        this->commandTransforms[commandName]->invokeOn(this->text, startInd, endInd);
//    }

	virtual ~BetterCommandInterface() = default;

protected:
    virtual std::vector<Command> initCommands() {
        std::vector<Command> commands;

        commands.push_back(Command("uppercase", std::make_shared<ToUpperTransform>()));
        commands.push_back(Command("paste", std::make_shared<PasteTransform>()));
        commands.push_back(Command("cut", std::make_shared<CutTransform>()));

        return commands;
    }
};

std::string BetterCommandInterface::savedCut;











std::shared_ptr<CommandInterface> buildCommandInterface(std::string& text) {
//    std::shared_ptr<BetterCommandInterface> interface = std::make_shared<BetterCommandInterface>(text);
    auto shr_ptr = std::make_shared<BetterCommandInterface>(text);
    std::shared_ptr<CommandInterface> ptr_to_base;
    ptr_to_base = shr_ptr;
//    std::shared_pointer_cast<CommandInterface>()
    ptr_to_base->init();
    return ptr_to_base;
//    std::static_pointer_cast()
//    return (std::shared_ptr<CommandInterface>) interface;
}






#endif // INITIALIZATION_H
