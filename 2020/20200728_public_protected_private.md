#### 类之间的public/protected/private继承

类之间的默认继承是privatge的，比如下面这个，Adult中的可以访问Person中的say，但是Dad就无法访问say和did，因为这两个接口在Audlt中已经private
```
 class Person {
    public:
        void say() {
            cout << " i say, i am " << name << endl;
        }
    protected:
        void did() {
            cout << " i did" << endl;
        }
    private:
        void think() {
            cout << " i think" << endl;
        }

    private:
        string name;
        int age;
};

class Adult: Person {
    public:
        void show() {
            say();
            did();
        }
};

class Dad: Adult {
    public:
        void comment() {
            show();
            say();
        }
};
```

#### 类内部的public/protected/private成员
