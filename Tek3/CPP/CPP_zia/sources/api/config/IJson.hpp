/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** IJson
*/

#ifndef IJSON_HPP_
#define IJSON_HPP_

#include <string>
#include <optional>
#include <vector>

/**
* @namespace Zia
* Zia API
*/
namespace Zia
{
    /**
    * @namespace Json
    * JSON-related types
    */
    namespace Json
    {
        /**
        * @typedef Number
        * JSON number
        */
        using Number = double;

        /**
        * @typedef Integer
        * JSON integer
        * @note will be 64-bit wide on 64-bit platforms, 32-bit wide on 32-bit platforms and long bytes otherwise.
        */
        using Integer = std::conditional_t<sizeof(void*) == 8, int64_t, std::conditional_t<sizeof(void*) == 4, int32_t, long>>;

        /**
        * @typedef String
        * JSON string
        */
        using String = std::string;

        /**
        * @typedef Bool
        * JSON bool
        */
        using Bool = bool;

        class IObject;
        class IArray;

        /**
        * @class IContainer
        * Abstract container containing various JSON elements.
        * @param typename ...Args: the keys used to address objects within the container.
        * @note In case of a map, Args might be const std::string&,
        * in case of an array it might be size_t, in case of a stack / queue it might be nothing.
        * @note For all methods starting with `set`, any previous reference to the value at such key
        * will be invalidated.
        */
        template <typename ...Args>
        class IContainer
        {
            public:
                virtual ~IContainer(void) = default;

                /**
                * @fn getNumber
                * Get a number for a certain key. Returns std::nullopt when not found or type not matching,
                * and the corresponding Json::Number otherwise.
                * @param Args ...args: the key to address the number in the container
                * @return std::optional<Json::Number>: the optional number
                */
                virtual std::optional<Json::Number> getNumber(Args ...args) const = 0;

                /**
                * @fn getInteger
                * Get an integer for a certain key. Returns std::nullopt when not found or type not matching,
                * and the corresponding Json::Integer otherwise.
                * @param Args ...args: the key to address the integer in the container
                * @return std::optional<Json::Integer>: the optional integer
                */
                virtual std::optional<Json::Integer> getInteger(Args ...args) const = 0;

                /**
                * @fn getString
                * Get a string for a certain key. Returns std::nullopt when not found or type not matching,
                * and the corresponding Json::String otherwise.
                * @param Args ...args: the key to address the string in the container
                * @return std::optional<Json::String>: the optional string
                */
                virtual std::optional<Json::String> getString(Args ...args) const = 0;

                /**
                * @fn getBool
                * Get a bool for a certain key. Returns std::nullopt when not found or type not matching,
                * and the corresponding Json::Bool otherwise.
                * @param Args ...args: the key to address the bool in the container
                * @return std::optional<Json::Bool>: the optional bool
                */
                virtual std::optional<Json::Bool> getBool(Args ...args) const = 0;

                /**
                * @fn isNull
                * Check whether an element in the container is null or not.
                * Returns true if the value is null and false otherwise.
                * @param Args ...args: the key referencing the checked value
                * @return bool: the test result
                */
                virtual bool isNull(Args ...args) const = 0;

                /**
                * @fn isUndefined
                * Check whether an element in the container is undefined or not.
                * Returns true if the value is undefined and false otherwise.
                * @param Args ...args: the key referencing the checked value
                * @return bool: the test result
                */
                virtual bool isUndefined(Args ...args) const = 0;

                /**
                * @fn getObject
                * Get a object for a certain key. Returns nullptr when not found or type not matching,
                * and the corresponding pointer to Json::IObject otherwise.
                * @param Args ...args: the key to address the object in the container
                * @return IObject*: the optional object
                */
                virtual const IObject* getObject(Args ...args) const = 0;

                /**
                * @fn getArray
                * Get an array for a certain key. Returns nullptr when not found or type not matching,
                * and the corresponding pointer to Json::IArray otherwise.
                * @param Args ...args: the key to address the array in the container
                * @return IArray*: the optional array
                */
                virtual const IArray* getArray(Args ...args) const = 0;

                /**
                * @fn setNumber
                * Set a number at a certain location in the container.
                * @param Args ...args: the key in which the number will be inserted
                * @param Number value: the value to insert
                */
                virtual void setNumber(Args ...args, Number value) = 0;

                /**
                * @fn setInteger
                * Set an integer at a certain location in the container.
                * @param Args ...args: the key in which the integer will be inserted
                * @param Integer value: the value to insert
                */
                virtual void setInteger(Args ...args, Integer value) = 0;

                /**
                * @fn setString
                * Set a string at a certain location in the container.
                * @param Args ...args: the key in which the string will be inserted
                * @param const String &value: the value to insert
                */
                virtual void setString(Args ...args, const String &value) = 0;

                /**
                * @fn setBool
                * Set a bool at a certain location in the container.
                * @param Args ...args: the key in which the bool will be inserted
                * @param Bool value: the value to insert
                */
                virtual void setBool(Args ...args, Bool value) = 0;

                /**
                * @fn setNull
                * Set the value at certain location in the container to null.
                * @param Args ...args: the key in which the null will be inserted
                */
                virtual void setNull(Args ...args) = 0;

                /**
                * @fn setUndefined
                * Set the value at certain location in the container to undefined.
                * @param Args ...args: the key in which the undefined will be inserted
                */
                virtual void setUndefined(Args ...args) = 0;

                /**
                * @fn getObject
                * Get a object for a certain key. Returns nullptr when not found or type not matching,
                * and the corresponding pointer to Json::IObject otherwise.
                * @param Args ...args: the key to address the object in the container
                * @return IObject*: the optional object
                */
                virtual IObject* getObject(Args ...args) = 0;

                /**
                * @fn getArray
                * Get an array for a certain key. Returns nullptr when not found or type not matching,
                * and the corresponding pointer to Json::IArray otherwise.
                * @param Args ...args: the key to address the array in the container
                * @return IArray*: the optional array
                */
                virtual IArray* getArray(Args ...args) = 0;

                /**
                * @fn createEmptyObject
                * Create an empty object at a certain location in the container.
                * @param Args ...args: the key in which the empty object will be inserted
                * @return IObject&: the reference to the created object
                */
                virtual IObject& createEmptyObject(Args ...args) = 0;

                /**
                * @fn createEmptyArray
                * Create an empty array at a certain location in the container.
                * @param Args ...args: the key in which the empty array will be inserted
                * @return IArray&: the reference to the created array
                */
                virtual IArray& createEmptyArray(Args ...args) = 0;

                /**
                * @fn clear
                * Remove all values in the container.
                * @note All references / pointers to values retrieved from this object
                * will be invalidated.
                */
                virtual void clear(void) = 0;
        };

        /**
        * @class IObject
        * Abstract JSON object.
        * @note The key type is `const std::string&`, which means the function to implement
        * for `setString` is `void setString(const std::string &key, const String &value) override`.
        */
        class IObject : public IContainer<const std::string&>
        {
            public:
                virtual ~IObject(void) = default;

                /**
                * @fn getKeys
                * Get all the keys referencing each value in the object.
                * @return std::vector<std::string>: the keys
                * @note A value is returned instead of a reference. This design assumes this method
                * will not be called frequently, and we can reasonably create from scratch the response.
                * It also lets the implementation not to maintain the same object with the keys.
                */
                virtual std::vector<std::string> getKeys(void) const = 0;
        };

        /**
        * @class IObject
        * Abstract JSON array.
        * @note The key type is `size_t`, which means the function to implement
        * for `setString` is `void setString(size_t index, const String &value) override`.
        * Set values will insert the value in the array so that the inserted value is located at the specified index.
        * Setting undefined will not change the index of any element in the array.
        */
        class IArray : public IContainer<size_t>
        {
            public:
                virtual ~IArray(void) = default;

                /**
                * @fn getSize
                * Get the size of the array.
                * @return size_t: the size of the array
                */
                virtual size_t getSize(void) const = 0;

                /**
                * @fn remove
                * Remove a value at a certain index. This will decrement the index of all values
                * with an index superior to index.
                * @param size_t index: the index of the value to remove
                */
                virtual void remove(size_t index) = 0;
        };
    }
} // namespace Zia

#endif /* !IJSON_HPP_ */
