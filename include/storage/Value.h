#ifndef VALUE_H
#define VALUE_H

#include <string>
#include <iostream>

enum class DataType { INT, FLOAT, STRING };

class Value {
public:
    virtual ~Value() {}
    virtual DataType getType() const = 0;
    virtual bool operator>(const Value& other) const = 0;
    virtual bool operator<(const Value& other) const = 0;
    virtual bool operator==(const Value& other) const = 0;
    virtual bool operator!=(const Value& other) const = 0;
    virtual std::string toString() const = 0;
};

class IntValue : public Value {
public:
    int val;
    IntValue(int v) : val(v) {}
    DataType getType() const override { return DataType::INT; }
    
    bool operator>(const Value& other) const override {
        return val > static_cast<const IntValue&>(other).val;
    }
    bool operator<(const Value& other) const override {
        return val < static_cast<const IntValue&>(other).val;
    }
    bool operator==(const Value& other) const override {
        return val == static_cast<const IntValue&>(other).val;
    }
    bool operator!=(const Value& other) const override {
        return val != static_cast<const IntValue&>(other).val;
    }
    std::string toString() const override { return std::to_string(val); }
};

class FloatValue : public Value {
public:
    float val;
    FloatValue(float v) : val(v) {}
    DataType getType() const override { return DataType::FLOAT; }

    bool operator>(const Value& other) const override {
        return val > static_cast<const FloatValue&>(other).val;
    }
    bool operator<(const Value& other) const override {
        return val < static_cast<const FloatValue&>(other).val;
    }
    bool operator==(const Value& other) const override {
        return val == static_cast<const FloatValue&>(other).val;
    }
    bool operator!=(const Value& other) const override {
        return val != static_cast<const FloatValue&>(other).val;
    }
    std::string toString() const override { return std::to_string(val); }
};

class StringValue : public Value {
public:
    std::string val;
    StringValue(const std::string& v) : val(v) {}
    DataType getType() const override { return DataType::STRING; }

    bool operator>(const Value& other) const override {
        return val > static_cast<const StringValue&>(other).val;
    }
    bool operator<(const Value& other) const override {
        return val < static_cast<const StringValue&>(other).val;
    }
    bool operator==(const Value& other) const override {
        return val == static_cast<const StringValue&>(other).val;
    }
    bool operator!=(const Value& other) const override {
        return val != static_cast<const StringValue&>(other).val;
    }
    std::string toString() const override { return val; }
};

#endif
