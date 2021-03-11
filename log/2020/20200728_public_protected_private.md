#### 类之间的private继承

类之间的默认继承是privatge的，会把基类中的所有public，protected变成private。

比如下面这个，Adult中的可以访问Person中的say，但是Dad就无法访问say和did，因为这两个接口在Audlt中已经private

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

#### 类之间的protected继承

public的成员在派生类中变成protected，protected的成员在派生类中还是protected，这样只允许父类访问。

#### 类之间的public继承

public的成员在派生类中还是public，protected的还是protected， private的还是private。

#### 总结，类之间的public/protected/private是一个最大权限，这个权限和成员原有的权限相比，取较小的权限就是在派生类中的权限。


#### 类内部的public/protected/private成员
