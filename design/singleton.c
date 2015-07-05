// Example for singleton pattern
// class definition
class MySingleton {
private:
// Private Constructor
    MySingleton();
// Stop the compiler generating methods of copy the object
    MySingleton(const MySingleton &copy);    // Not Implemented
    MySingleton &operator=(const MySingleton &copy);    // Not Implemented
    static MySingleton *m_pInstance;
public:
    static MySingleton *getSharedInstance() {
        if (!m_pInstance) {
            m_pInstance = new MySingleton;
        }
        return m_pInstance;
    }
};

// in the source file
MySingleton *MySingleton::m_pInstance = NULL;

注意，本例中的实现方式针对非多线程的情况。如果有过个线程想要同时调用getSharedInstance函数，则需要用mutex保护下列代码：
        pthread_mutex_lock(&mutex);
        if (!m_pInstance) {
            m_pInstance = new MySingleton;
        }
        pthread_mutex_unlock(&mutex);

