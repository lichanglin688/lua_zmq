#ifndef SINGLETON_H
#define SINGLETON_H
#include <QMutex>
#include <QMutexLocker>

template <class T>
class Singleton
{
public:
   static T * getSingleton()
   {
       if (m_pSingleton)
          return m_pSingleton;

       QMutexLocker locker(&m_oMutexSingleton);
       if (! m_pSingleton) { m_pSingleton = new T(); }

       return m_pSingleton;
   }
   static void deleteSingleton()
   {
       if (! m_pSingleton) { return; }

       QMutexLocker locker(&m_oMutexSingleton);
       delete m_pSingleton;
       m_pSingleton = nullptr;
   }

protected:

   Singleton(){ ; }
   virtual ~Singleton() { ; }

private:

   static T *     m_pSingleton;
   static QMutex  m_oMutexSingleton;

};

template <class T> T * Singleton<T>::m_pSingleton = NULL;
template <class T> QMutex Singleton<T>::m_oMutexSingleton;
#endif
