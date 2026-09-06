/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** Json
*/

#ifndef JSON_HPP_
#define JSON_HPP_

#define DEFAULT_JSON__ "{\
  \"servers\": [\
    {\
      \"ip\": \"127.0.0.1\",\
      \"port\": 80\
    },\
    {\
      \"ip\": \"127.0.0.1\",\
      \"port\": 443\
    }\
  ],\
  \"connection_wrapper\": {\
    \"path\": \"./build/modules/lib/libModuleConnectionWrapper\",\
    \"conf\": \"./modules/connection_wrapper/conf/config.json\"\
  },\
  \"parser\": {\
    \"path\": \"./build/modules/lib/libModuleParser\",\
    \"conf\": \"./modules/parser/conf/config.json\"\
  }\
}"

#include <nlohmann/json.hpp>

#include "IJson.hpp"

/**
* @namespace Zia
* Zia API
*/
namespace Zia
{
    /**
    * @namespace Json
    * Json API
    */
    namespace Json
    {
        /**
         * @class Object
         * Herite of IObject
         * Represent a Js Object (use to manipule config file)
         */
        class Object : public IObject
        {
            private:
                nlohmann::json _json;
            public:
                /**
                 * @brief Construct a new Object object
                 * @param json library of Json Parsing
                 */
                Object(nlohmann::json json);
                /**
                 * @brief Construct a new Object object
                 * @param obj Another Object class
                 */
                Object(const Object *obj);
                /**
                 * @brief Construct a new Object object
                 * @param nameFile path to config file
                 */
                Object(const std::string &nameFile);
                ~Object(void) = default;

                    // Tools
                void operator=(const Object &element);
                void operator=(nlohmann::json json);
                friend std::ostream &operator<<(std::ostream &os, Object &element)
                { return os << element._json << std::endl; }
                friend void operator>>(Object& obj, std::string &str)
                { str = obj._json.dump(); }
                ////////////////////////////////////////

                /**
                 * @fn getKeys
                 * Herite of IObject
                 * Take all "key" in current object
                 * @return std::vector<std::string> All "key"
                 */
                std::vector<std::string> getKeys(void) const final;

                /**
                * @fn getNumber
                * Get a number for a certain key. Returns std::nullopt when not found or type not matching,
                * and the corresponding Json::Number otherwise.
                * @param Args ...args: the key to address the number in the container
                * @return std::optional<Json::Number>: the optional number
                */
                std::optional<Json::Number> getNumber(const std::string &args) const final;
                /**
                * @fn getInteger
                * Get an integer for a certain key. Returns std::nullopt when not found or type not matching,
                * and the corresponding Json::Integer otherwise.
                * @param Args ...args: the key to address the integer in the container
                * @return std::optional<Json::Integer>: the optional integer
                */
                std::optional<Json::Integer> getInteger(const std::string &args) const final;
                /**
                * @fn getString
                * Get a string for a certain key. Returns std::nullopt when not found or type not matching,
                * and the corresponding Json::String otherwise.
                * @param Args ...args: the key to address the string in the container
                * @return std::optional<Json::String>: the optional string
                */
                std::optional<Json::String> getString(const std::string &args) const final;
                /**
                * @fn getBool
                * Get a bool for a certain key. Returns std::nullopt when not found or type not matching,
                * and the corresponding Json::Bool otherwise.
                * @param Args ...args: the key to address the bool in the container
                * @return std::optional<Json::Bool>: the optional bool
                */
                std::optional<Json::Bool> getBool(const std::string &args) const final;
                /**
                * @fn isNull
                * Check whether an element in the container is null or not.
                * Returns true if the value is null and false otherwise.
                * @param Args ...args: the key referencing the checked value
                * @return bool: the test result
                */
                bool isNull(const std::string &args) const final;
                /**
                * @fn isUndefined
                * Check if args exist or not
                * @param Args ...args: the key referencing the checked value
                * @return bool: the test result
                */
                bool isUndefined(const std::string &args) const final;
                /**
                * @fn getObject
                * Get a object for a certain key. Returns nullptr when not found or type not matching,
                * and the corresponding pointer to Json::IObject otherwise.
                * @param Args ...args: the key to address the object in the container
                * @return IObject*: the optional object
                */
                const IObject* getObject(const std::string &args) const final;
                /**
                * @fn getArray
                * Get an array for a certain key. Returns nullptr when not found or type not matching,
                * and the corresponding pointer to Json::IArray otherwise.
                * @param Args ...args: the key to address the array in the container
                * @return IArray*: the optional array
                */
                const IArray* getArray(const std::string &args) const final;
                /**
                * @fn setNumber
                * Set a number at a certain location in the container.
                * @param Args ...args: the key in which the number will be inserted
                * @param Number value: the value to insert
                */
                void setNumber(const std::string &args, Number value) final;
                /**
                * @fn setInteger
                * Set an integer at a certain location in the container.
                * @param Args ...args: the key in which the integer will be inserted
                * @param Integer value: the value to insert
                */
                void setInteger(const std::string &args, Integer value) final;
                /**
                * @fn setString
                * Set a string at a certain location in the container.
                * @param Args ...args: the key in which the string will be inserted
                * @param const String &value: the value to insert
                */
                void setString(const std::string &args, const String &value) final;
                /**
                * @fn setBool
                * Set a bool at a certain location in the container.
                * @param Args ...args: the key in which the bool will be inserted
                * @param Bool value: the value to insert
                */
                void setBool(const std::string &args, Bool value) final;
                /**
                * @fn setNull
                * Set the value at certain location in the container to null.
                * @param Args ...args: the key in which the null will be inserted
                */
                void setNull(const std::string &args) final;
                /**
                * @fn setUndefined
                * Set the value at certain location in the container to null.
                * @param Args ...args: the key in which the undefined will be inserted
                */
                void setUndefined(const std::string &args) final;
                /**
                * @fn getObject
                * Get a object for a certain key. Returns nullptr when not found or type not matching,
                * and the corresponding pointer to Json::IObject otherwise.
                * @param Args ...args: the key to address the object in the container
                * @return IObject*: the optional object
                */
                IObject* getObject(const std::string &args) final;
                /**
                * @fn getArray
                * Get an array for a certain key. Returns nullptr when not found or type not matching,
                * and the corresponding pointer to Json::IArray otherwise.
                * @param Args ...args: the key to address the array in the container
                * @return IArray*: the optional array
                */
                IArray* getArray(const std::string &args) final;
                /**
                * @fn createEmptyObject
                * Create an empty object at a certain location in the container.
                * @param Args ...args: the key in which the empty object will be inserted
                * @return IObject&: the reference to the created object
                */
                IObject& createEmptyObject(const std::string &args) final;
                /**
                * @fn createEmptyArray
                * Create an empty array at a certain location in the container.
                * @param Args ...args: the key in which the empty array will be inserted
                * @return IArray&: the reference to the created array
                */
                IArray& createEmptyArray(const std::string &args) final;
                /**
                * @fn clear
                * Remove all values in the container.
                * @note All references / pointers to values retrieved from this object
                * will be invalidated.
                */
                void clear(void) final;
        };

        /**
         * @class Array
         * Herite of IArray
         * Represent a Js Array (use to manipule config file)
         */
        class Array : public IArray
        {
            private:
                nlohmann::json _json;
                const std::string& getIndex(size_t index) const;
            public:
                /**
                 * @brief Construct a new Array object
                 * @param json library of Json Parsing
                 */
                Array(nlohmann::json json);
                /**
                 * @brief Construct a new Array object
                 * @param obj Another Array ptr
                 */
                Array(const Array *obj);
                /**
                 * @brief Construct a new Array object
                 * @param nameFile path config file
                 */
                Array(const std::string &nameFile);
                ~Array(void) = default;

                    // Tools
                void operator=(const Array &element);
                void operator=(nlohmann::json json);
                friend std::ostream &operator<<(std::ostream &os, Array &element)
                { return os << element._json << std::endl; }
                ///////////////////////////////

                /**
                 * @fn getSize
                 * Herited of IArray
                 * Get the Size of Array
                 * @return size_t size of array
                 */
                size_t getSize(void) const final;
                /**
                 * @fn remove
                 * Herited of IArray
                 * Remove element of array
                 * @return size_t index of element
                 */
                void remove(size_t index) final;

                /**
                * @fn getNumber
                * Get a number for a certain key. Returns std::nullopt when not found or type not matching,
                * and the corresponding Json::Number otherwise.
                * @param Args ...args: the key to address the number in the container
                * @return std::optional<Json::Number>: the optional number
                */
                std::optional<Json::Number> getNumber(size_t args) const final;
                /**
                * @fn getInteger
                * Get an integer for a certain key. Returns std::nullopt when not found or type not matching,
                * and the corresponding Json::Integer otherwise.
                * @param Args ...args: the key to address the integer in the container
                * @return std::optional<Json::Integer>: the optional integer
                */
                std::optional<Json::Integer> getInteger(size_t args) const final;
                /**
                * @fn getString
                * Get a string for a certain key. Returns std::nullopt when not found or type not matching,
                * and the corresponding Json::String otherwise.
                * @param Args ...args: the key to address the string in the container
                * @return std::optional<Json::String>: the optional string
                */
                std::optional<Json::String> getString(size_t args) const final;
                /**
                * @fn getBool
                * Get a bool for a certain key. Returns std::nullopt when not found or type not matching,
                * and the corresponding Json::Bool otherwise.
                * @param Args ...args: the key to address the bool in the container
                * @return std::optional<Json::Bool>: the optional bool
                */
                std::optional<Json::Bool> getBool(size_t args) const final;
                /**
                * @fn isNull
                * Check whether an element in the container is null or not.
                * Returns true if the value is null and false otherwise.
                * @param Args ...args: the key referencing the checked value
                * @return bool: the test result
                */
                bool isNull(size_t args) const final;
                /**
                * @fn isUndefined
                * Check if args exist or not
                * @param Args ...args: the key referencing the checked value
                * @return bool: the test result
                */
                bool isUndefined(size_t args) const final;
                /**
                * @fn getObject
                * Get a object for a certain key. Returns nullptr when not found or type not matching,
                * and the corresponding pointer to Json::IObject otherwise.
                * @param Args ...args: the key to address the object in the container
                * @return IObject*: the optional object
                */
                const IObject* getObject(size_t args) const final;
                /**
                * @fn getArray
                * Get an array for a certain key. Returns nullptr when not found or type not matching,
                * and the corresponding pointer to Json::IArray otherwise.
                * @param Args ...args: the key to address the array in the container
                * @return IArray*: the optional array
                */
                const IArray* getArray(size_t args) const final;
                /**
                * @fn setNumber
                * Set a number at a certain location in the container.
                * @param Args ...args: the key in which the number will be inserted
                * @param Number value: the value to insert
                */
                void setNumber(size_t args, Number value) final;
                /**
                * @fn setInteger
                * Set an integer at a certain location in the container.
                * @param Args ...args: the key in which the integer will be inserted
                * @param Integer value: the value to insert
                */
                void setInteger(size_t args, Integer value) final;
                /**
                * @fn setString
                * Set a string at a certain location in the container.
                * @param Args ...args: the key in which the string will be inserted
                * @param const String &value: the value to insert
                */
                void setString(size_t args, const String &value) final;
                /**
                * @fn setBool
                * Set a bool at a certain location in the container.
                * @param Args ...args: the key in which the bool will be inserted
                * @param Bool value: the value to insert
                */
                void setBool(size_t args, Bool value) final;
                /**
                * @fn setNull
                * Set the value at certain location in the container to null.
                * @param Args ...args: the key in which the null will be inserted
                */
                void setNull(size_t args) final;
                /**
                * @fn setUndefined
                * Set the value at certain location in the container to null.
                * @param Args ...args: the key in which the undefined will be inserted
                */
                void setUndefined(size_t args) final;
                /**
                * @fn getObject
                * Get a object for a certain key. Returns nullptr when not found or type not matching,
                * and the corresponding pointer to Json::IObject otherwise.
                * @param Args ...args: the key to address the object in the container
                * @return IObject*: the optional object
                */
                IObject* getObject(size_t args) final;
                /**
                * @fn getArray
                * Get an array for a certain key. Returns nullptr when not found or type not matching,
                * and the corresponding pointer to Json::IArray otherwise.
                * @param Args ...args: the key to address the array in the container
                * @return IArray*: the optional array
                */
                IArray* getArray(size_t args) final;
                /**
                * @fn createEmptyObject
                * Create an empty object at a certain location in the container.
                * @param Args ...args: the key in which the empty object will be inserted
                * @return IObject&: the reference to the created object
                */
                IObject& createEmptyObject(size_t args) final;
                /**
                * @fn createEmptyArray
                * Create an empty array at a certain location in the container.
                * @param Args ...args: the key in which the empty array will be inserted
                * @return IArray&: the reference to the created array
                */
                IArray& createEmptyArray(size_t args) final;
                /**
                * @fn clear
                * Remove all values in the container.
                * @note All references / pointers to values retrieved from this object
                * will be invalidated.
                */
                void clear(void) final;
        };
    } // namespace Json
} // namespace Zia


#endif /* !JSON_HPP_ */
