#ifndef ELEMENT_H
#define ELEMENT_H
#include <vector>
#include <map>
#include "../parsers/content-type/ContentParser.hpp"
#include "../parsers/Factory.hpp"

class Element
{
    public:
        virtual void getValue(void* v) = 0;
        virtual void read(std::string& text, const ContentParser* parser) {};
        virtual ~Element(){
        }
};

class ElementInt: public Element
{
    public:
        int value;
        void getValue(void* v)  {v = & value;}
        inline void read(std::string& text, const ContentParser* parser){ parser->parseContent(text, this); }
};

class ElementDouble: public Element
{
    public:
        double value;
        void getValue(void* v) {v = & value;}
        inline void read(std::string& text, const ContentParser* parser){ parser->parseContent(text, this); }
};

class ElementString: public Element
{
    public:
        std::string value;
        void getValue(void* v) {v = & value;}
        inline void read(std::string& text, const ContentParser* parser){ parser->parseContent(text, this); }
};

class ElementBoolean: public Element
{
    public:
        bool value;
        void getValue(void* v) {v = & value;}
        inline void read(std::string& text, const ContentParser* parser){ parser->parseContent(text, this); }
};

class ElementArray: public Element
{
    public:
        std::vector<Element*> values;
        void getValue(void* v) {v = & values;}
        inline void read(std::string& text, const ContentParser* parser){ parser->parseContent(text, this); }
        ~ElementArray(){
            for(std::vector<Element*>::const_iterator it = values.begin(); it != values.end(); it++)
                delete *it;
        }
};

class ElementObject: public Element
{
    public:
        std::map<std::string*, Element*> values;
        void getValue(void* v) {v = & values;}
        inline void read(std::string& text, const ContentParser* parser){ parser->parseContent(text, this); }
        ~ElementObject(){
            for(std::map<std::string*, Element*>::const_iterator it = values.begin(); it != values.end(); it++)
            {
                delete it->first;
                delete it->second;
            }
        }
};

#endif // ELEMENT_H
