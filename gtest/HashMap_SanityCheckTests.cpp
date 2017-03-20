// HashMap_SanityCheckTests.cpp
//
// ICS 45C Fall 2016
// Project #3: Maps and Legends
//
// This is a set of "sanity checking" unit tests for your HashMap
// implementation, provided primarily as a mechanism for ensuring
// that your implementation is compatible with the unit tests that
// we'll be using to test your implementation during grading.  The
// goal here is to ensure that you have all of the necessary member
// functions, and that you haven't made changes that you shouldn't.
//
// All of the tests are initially commented out, because none of them
// would link successfully.  (Interestingly, they all compile successfully,
// because HashMap.hpp declares all of the necessary member functions,
// but they will all result in link errors, since there are no
// implementations of any of HashMap's member functions until you
// write them.)
//
// As you implement member functions, you can start uncommenting unit
// tests -- and try to challenge yourself to understand which tests
// can be uncommented at which times, which is a useful exercise in
// learning more about how C++ compilers and linkers work, and what
// you can and can't do with partially-implemented classes.
//
// Note, too, that some of these tests attempt to do seemingly
// unnecessary things, like calling size() and then immediately
// incrementing it.  This is a simple mechanism to avoid compiler
// warnings about unused variables, while preserving the ability to
// declare those variables (and their types) to ensure that the
// return types of your member functions are correct.
//
// One more thing to realize is that there is no attempt here to
// actually validate the functionality of the HashMap class.  The
// only goal here is to make sure that you've declared and defined
// everything you need, so that this code will compile.  To test
// the functionality of your HashMap implementation, you'll need
// to write your own unit tests (in HashMapTests.cpp).  Don't copy
// these tests into your HashMapTests.cpp file, for the simple
// reason that these tests don't actually *test* anything, except
// that the member functions we expect are present.  The only thing
// that matters, for these tests, is that they compile and link;
// beyond that, they have no value.

#include <gtest/gtest.h>
#include <string>
#include "HashMap.hpp"


TEST(HashMap_SanityChecks, canConstructWithNoArguments)
{
    HashMap hm1;
}


TEST(HashMap_SanityChecks, canConstructWithLambdaExpression)
{
    HashMap hm1{[](const std::string& s) { return 0; }};
}


namespace
{
    unsigned int someHashFunction(const std::string& s)
    {
        return 19;
    }
}


TEST(HashMap_SanityChecks, canConstructWithFunction)
{
    HashMap hm1{someHashFunction};
}


namespace
{
    void takesHashMapByValue(HashMap hm)
    {
    }
}


TEST(HashMap_SanityChecks, canCopyConstruct)
{
    HashMap hm1;
    HashMap hm2{hm1};
    HashMap hm3 = hm2;
    takesHashMapByValue(hm1);
}


TEST(HashMap_SanityChecks, canAssign)
{
    HashMap hm1;
    HashMap hm2;
    hm1 = hm2;
}


TEST(HashMap_SanityChecks, canAddKeyValuePair)
{
    HashMap hm1;
    std::string key{"Boo"};
    std::string value{"perfect"};
    hm1.add(key, value);
}


TEST(HashMap_SanityChecks, canRemove)
{
    HashMap hm1;
    std::string key{"Alex"};
    hm1.remove(key);
}


TEST(HashMap_SanityChecks, canCheckIfContainsKey)
{
    HashMap hm1;
    std::string key{"Boo"};
    bool b = hm1.contains("Boo");
    b = !b;
}


TEST(HashMap_SanityChecks, canGetValueAssociatedWithKey)
{
    HashMap hm1;
    std::string key{"Boo"};
    std::string value = hm1.value(key);
}


TEST(HashMap_SanityCheckTests, canGetSize)
{
    HashMap hm1;
    unsigned int i = hm1.size();
    ++i;
}


TEST(HashMap_SanityCheckTests, canGetBucketCount)
{
    HashMap hm1;
    unsigned int b = hm1.bucketCount();
    ++b;
}


TEST(HashMap_SanityCheckTests, canGetLoadFactor)
{
    HashMap hm1;
    double lf = hm1.loadFactor();
    lf += 1.0;
}


TEST(HashMap_SanityCheckTests, canGetMaxBucketSize)
{
    HashMap hm1;
    unsigned int mbs = hm1.maxBucketSize();
    ++mbs;
}

