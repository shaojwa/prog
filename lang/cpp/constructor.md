https://stackoverflow.com/questions/1025313/will-an-empty-constructor-or-destructor-do-the-same-thing-as-the-generated-one


1. There is one important difference regarding initialization. If you put a user declared constructor, your type does not receive value initialization of members anymore, and it is up to your constructor to do any initialization that's needed. Example:

1.  Because writing the destructor will require a working base-class destructor.
