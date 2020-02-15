

#ifndef MON_H
#define MON_H

class Mon
{
public:
    static Mon* getInst(void) 
    {
        if (!m_inited) 
        {
            m_instance = new Mon();
            m_inited = true;
        }
        return m_instance;
    };
    bool init();
    bool StartMonThread();
    static bool Check(bool& need_reconnect);

private:
    static Mon *m_instance;
    static bool m_inited;
    static bool m_network_ok;
};

#endif
