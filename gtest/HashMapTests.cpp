// HashMapTests.cpp
//
// ICS 45C Fall 2016
// Project #3: Maps and Legends
//
// Write unit tests for your HashMap class here.  I've provided one test already,
// though I've commented it out, because it won't compile until you've implemented
// three things: the HashMap constructor, the HashMap destructor, and HashMap's
// size() member function.

#include <gtest/gtest.h>
#include "HashMap.hpp"


TEST(TestHashMap, sizeOfNewlyCreatedHashMapIsZero)
{
    HashMap empty;
    ASSERT_EQ(0, empty.size());
}

TEST(TestHashMap, testAdd)
{
    HashMap myHashMap;

    std::string keys[10] = {"Albert", "Bob", "Christina", "Diane", "Elena", "F", "G", "H", "I"};
    std::string values[10] = {"AAA", "BBB", "CCC", "DDD", "EEE", "FFF", "GGG", "HHH", "III"};


    for(int i = 0; i < 10; i++){
        myHashMap.add(keys[i], values[i]);
    }

    for(int i = 0; i < 10; i++){
         ASSERT_EQ(myHashMap.value(keys[i]), values[i]);
    }

}

TEST(TestHashMap, testRemove)
{
    HashMap myHashMap;

    std::string keys[10] = {"Albert", "Bob", "Christina", "Diane", "Elena", "F", "G", "H", "I"};
    std::string values[10] = {"AAA", "BBB", "CCC", "DDD", "EEE", "FFF", "GGG", "HHH", "III"};


    for(int i = 0; i < 10; i++){
        myHashMap.add(keys[i], values[i]);
    }

    for(int i = 0; i < 10; i++){
        ASSERT_TRUE(myHashMap.contains(keys[i]));
    }

    for(int i = 0; i < 10; i++){
        if(i % 2 == 0){
            myHashMap.remove(keys[i]);
        }
    }


    for(int i = 0; i < 10; i++){
        if(i % 2 == 0){
            ASSERT_FALSE(myHashMap.contains(keys[i]));
        }
    }
}

TEST(TestHashMap, testSize)
{
    HashMap myHashMap;

    for(int i = 0; i < 100; i++){
        myHashMap.add(std::to_string(i) + std::to_string(i) + "J", "AA");
        for(int j = 0; j < 100; j++){
            myHashMap.add(std::to_string(i) + std::to_string(i) + "J" , "A" + std::to_string(i));
        }
        ASSERT_EQ(myHashMap.size(), i + 1);
    }

    ASSERT_EQ(myHashMap.size(), 100);

    for(int i = 0; i < 100; i++){
        myHashMap.remove(std::to_string(i) + std::to_string(i) + "J");
    }

    ASSERT_EQ(myHashMap.size(), 0);

}

TEST(TestHashMap, testBucketCount)
{
    HashMap myHashMap;

    std::string keys[10] = {"Albert", "Bob", "Christina", "Diane", "Elena", "F", "G", "H", "I"};
    std::string values[10] = {"AAA", "BBB", "CCC", "DDD", "EEE", "FFF", "GGG", "HHH", "III"};


    for(int i = 0; i < 10; i++){
        myHashMap.add(keys[i], values[i]);

        if(i == 8){
            ASSERT_EQ(myHashMap.bucketCount(), 21);
        }

    }

}

TEST(TestHashMap, testLoadFactor){
    HashMap myHashMap;

    std::string keys[12] = {"Albert", "Bob", "Christina", "Diane", "Elena", "F", "G", "H", "I", "J", "K"};
    std::string values[12] = {"AAA", "BBB", "CCC", "DDD", "EEE", "FFF", "GGG", "HHH", "III", "JJJ", "KKK"};


    for(int i = 0; i < 12; i++){
        myHashMap.add(keys[i], values[i]);

        if(i == 7){
            ASSERT_FLOAT_EQ(myHashMap.loadFactor(), 0.8);
        }

    }

}

TEST(TestHashMap, testCopyConstructor){
    HashMap myHashMap;


    std::string keys[12] = {"Albert", "Bob", "Christina", "Diane", "Elena", "F", "G", "H", "I", "J", "K"};
    std::string values[12] = {"AAA", "BBB", "CCC", "DDD", "EEE", "FFF", "GGG", "HHH", "III", "JJJ", "KKK"};


    for(int i = 0; i < 12; i++) {
        myHashMap.add(keys[i], values[i]);
    }

    HashMap secondHM{myHashMap};

    for(int i = 0; i < 12; i++) {
        ASSERT_EQ(secondHM.value(keys[i]), values[i]);
    }

    myHashMap.remove("Albert");

    ASSERT_EQ(secondHM.size(), 12);
    ASSERT_EQ(myHashMap.size(), 11);

}

TEST(TestHashMap, testAssignmentOperator){
    HashMap myHashMap;


    std::string keys[12] = {"Albert", "Bob", "Christina", "Diane", "Elena", "F", "G", "H", "I", "J", "K"};
    std::string values[12] = {"AAA", "BBB", "CCC", "DDD", "EEE", "FFF", "GGG", "HHH", "III", "JJJ", "KKK"};


    for(int i = 0; i < 12; i++) {
        myHashMap.add(keys[i], values[i]);
    }

    HashMap& refHashMap = myHashMap;

    for(int i = 0; i < 12; i++) {
        ASSERT_EQ(refHashMap.value(keys[i]), values[i]);
    }

    refHashMap.remove("Christina");
    refHashMap.remove("Albert");

    ASSERT_FALSE(myHashMap.contains("Christina"));
    ASSERT_FALSE(myHashMap.contains("Albert"));

}



