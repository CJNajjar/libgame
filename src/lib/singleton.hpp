#ifndef _LIB_SINGLETON_HPP
#define _LIB_SINGLETON_HPP
template<typename T>
abstract class singleton{
  protected:
    T* m_instance;
  public:
    static T instance(){
        if (m_instance == NULL) m_instance = new T;
        ASSERT(m_instance != NULL);
        return m_instance;
    };
};
template <typename T> T* CSingleton<T>::m_instance = NULL;
#endif // _LIB_SINGLETON_HPP
