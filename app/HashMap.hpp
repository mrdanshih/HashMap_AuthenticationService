// HashMap.hpp
//
// ICS 45C Fall 2016
// Project #3: Maps and Legends
//
// This header file contains a declaration for a HashMap class, which
// is a separately-chained hash table implementation of a map (i.e.,
// a collection of key/value pairs), where the keys and values are
// strings.  This HashMap consists of a dynamically-allocated array
// of "buckets", each of which is a pointer to the first node in a
// linked list of key/value pairs that have hashed to that bucket.
//
// You may not make changes to the members of this class as they are
// declared now, since we will be running unit tests against your class
// that will expect these declarations not to have changed (and that
// its member functions are implemented as specified below).  However,
// you are free to add whatever additional members you feel are necessary,
// including new member variables or member functions.

#ifndef HASHMAP_HPP
#define HASHMAP_HPP

#include <functional>
#include <string>



class HashMap
{
public:
    // This is called a "typedef", which is a way to give a synonym to an
    // existing type.  In this case, we're introducing HashFunction as a
    // new name for a type representing a function that takes a reference
    // to a const string and returns an unsigned int.  Given that, a
    // variable or parameter of type HashFunction can be assigned such
    // a function.
    //
    // Hash functions must conform to these properties:
    //
    // (1) Given a particular string s repeatedly, they must always
    //     return the same hash value.
    // (2) They do not take the number of buckets into account (as they
    //     do not receive a parameter that tells them how many buckets
    //     there are).  Any unsigned int value is fair game as a result.
    //     It will be the job of the HashMap class to reduce the results
    //     to the range of available bucket indices (e.g., by using the
    //     % operator).
    typedef std::function<unsigned int(const std::string&)> HashFunction;

    // This constant specifies the number of buckets that a HashMap will
    // have when it is initially constructed.
    static constexpr unsigned int initialBucketCount = 10;


public:
    // This constructor initializes the HashMap to use whatever default
    // hash function you'd like it to use.  A little research online will
    // yield some good ideas about how to write a good hash function for
    // strings; don't just return zero or, say, the length of the string.
    HashMap();

    // This constructor instead initializes the HashMap to use a particular
    // hash function instead of the default.  (We'll use this in our unit
    // tests to control the scenarios more carefully.)
    HashMap(HashFunction hasher);

    // The "Big Three" need to be implemented appropriately, so that HashMaps
    // can be created, destroyed, copied, and assigned without leaking
    // resources, interfering with one another, or causing crashes or
    // undefined behavior.
    HashMap(const HashMap& hm);
    ~HashMap();
    HashMap& operator=(const HashMap& hm);

    // add() takes a key and a value.  If the key is not already stored in
    // this HashMap, the key/value pair is added; if the key is already
    // stored, the function has no effect.
    //
    // If adding the new key/value pair will cause the load factor of this
    // HashMap to exceed 0.8, the following must happen:
    //
    // (1) The number of buckets should be increased by doubling it and
    //     adding 1 (i.e., if there were 10 buckets, increase it to
    //     2 * 10 + 1 = 21).
    // (2) All key/value pairs should be rehashed into their new buckets,
    //     important because changing the number of buckets will likely
    //     change which bucket a particular key hashes to (especialy if
    //     you're using % to determine the index of that bucket).
    void add(const std::string& key, const std::string& value);

    // remove() takes a key and removes it (and its associated value) from
    // this HashMap if it is already present; if not, the function has no
    // effect.
    void remove(const std::string& key);

    // contains() returns true if the given key is in this HashMap, false
    // if not.
    bool contains(const std::string& key) const;

    // value() returns the value associated with the given key in this HashMap
    // if the key is stored in this HashMap; if not, the empty string is
    // returned.  (Going forward, we'll discover that throwing an exception
    // is a better way to handle the scenario where the key is not present,
    // but we'll conquer that at a later date.)
    std::string value(const std::string& key) const;

    // size() returns the number of key/value pairs stored in this HashMap.
    unsigned int size() const;

    // bucketCount() returns the number of buckets currently allocated in
    // this HashMap.
    unsigned int bucketCount() const;

    // loadFactor() returns the proportion of the number of key/value pairs
    // to the number of buckets, a measurement of how "full" the HashMap is.
    // For example, if there are 20 key/value pairs and 50 buckets, we would
    // say that the load factor is 20/50 = 0.4.
    double loadFactor() const;

    // maxBucketSize() returns the number of key/value pairs stored in this
    // HashMap's largest bucket.
    unsigned int maxBucketSize() const;

    //Print self
    void printSelf();

private:
    // This structure describes the nodes that make up the linked lists in
    // each of this HashMap's buckets.
    struct Node
    {
        std::string key;
        std::string value;
        Node* next;
    };

    void copyBuckets(Node** source, Node** destination, unsigned int size);

    void rebuildMap(Node** oldBuckets, unsigned int oldNumBuckets);


    // Store the hash function (either the default hash function or the one
    // passed to the constructor as a parameter) in this member variable.
    // When you want to hash a key, call this member variable (i.e., follow
    // it with parentheses and a parameter) just like you would any other
    // function.
    HashFunction hasher;


    // You will no doubt need to add at least a few more private members
    Node** buckets;

    unsigned int numBuckets;
    unsigned int numItems;


};



#endif // HASHMAP_HPP

