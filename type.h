#ifndef TYPESYSTEM_H
#define TYPESYSTEM_H
#include "./pch.h"
using namespace std;

enum ValueType
{
    VALUE_BOOL = 1,
    VALUE_INT,
    VALUE_CHAR,
    VALUE_VOID,
    VALUE_STRING,
    VALUE_STRUCT,

    VALUE_INT_POINTER,
    VALUE_CHAR_POINTER,
    COMPOSE_STRUCT,
    COMPOSE_UNION,
    COMPOSE_FUNCTION
};

class Type
{
public:
    ValueType type;
    Type(ValueType valueType);
public:  
    
    ValueType* childType; // for union or struct
    ValueType* paramType, retType; // for function
    
    void addChild(Type* t);
    void addParam(Type* t);
    void addRet(Type* t);
public:
    ValueType* sibling; 
public:
    string getTypeInfo();
};

// 设置几个常量Type，可以节省空间开销
static Type* TYPE_INT = new Type(VALUE_INT);
static Type* TYPE_CHAR = new Type(VALUE_CHAR);
static Type* TYPE_BOOL = new Type(VALUE_BOOL);
static Type* TYPE_VOID = new Type(VALUE_VOID);
static Type* TYPE_STRUCT = new Type(VALUE_STRUCT);
static Type* TYPE_STRING = new Type(VALUE_STRING);
static Type* TYPE_INT_POINTER = new Type(VALUE_INT_POINTER);
static Type* TYPE_CHAR_POINTER = new Type(VALUE_CHAR_POINTER);


int getSize(Type* type);

#endif