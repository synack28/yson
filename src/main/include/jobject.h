#ifndef JOBJECT_H
#define JOBJECT_H

#include <string>
#include <vector>
#include <map>
#include <ctime>
#include <memory>

#include "jvalue.h"
#include "jarray.h"
#include "jnull.h"

namespace yson {

    class JArray;

    class JObject : public JValue {
        private:
            std::map<std::string, std::shared_ptr<JValue>> values;
            std::vector<std::string> keys;
            std::map<std::string, int> index;

        public:
            JObject();
            void addValue(std::string name, std::shared_ptr<JValue> value);
            void addValue(std::string name, JObject value);
            void addValue(std::string name, JArray value);
            void addValue(std::string name, JNull value);
            void addNumber(std::string name, int64_t value);
            void addNumber(std::string name, uint64_t value);
            void addNumber(std::string name, double value);
            void addBoolean(std::string name, bool value);
            void addString(std::string name, std::string value);
            void addDate(std::string name, time_t time);

            void remove(std::string name);

            const std::string toString() const;
    };

}

#endif