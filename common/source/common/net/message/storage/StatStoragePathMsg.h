#ifndef STATSTORAGEPATHMSG_H_
#define STATSTORAGEPATHMSG_H_

#include <common/net/message/SimpleUInt16Msg.h>


class StatStoragePathMsg : public SimpleUInt16Msg
{
   public:
      /**
       * @param targetID only used for storage servers, value ignored for other nodes (but may not
       * be NULL!)
       */
      StatStoragePathMsg(uint16_t targetID) :
         SimpleUInt16Msg(NETMSGTYPE_StatStoragePath, targetID)
      {
      }


   protected:
      /**
       * For deserialization only!
       */
      StatStoragePathMsg() : SimpleUInt16Msg(NETMSGTYPE_StatStoragePath)
      {
      }


   private:


   public:
  std::string ToString() {
    std::ostringstream oss;
    struct timespec t;
    clock_gettime(CLOCK_MONOTONIC, &t);
    oss << "StatStoragePath" << " - " << CURR_MICROS(t) << " : ";
    oss << "targetID: " << getValue();
    return oss.str();

  }
      // getters & setters
      uint16_t getTargetID() const
      {
         return getValue();
      }

};

#endif /*STATSTORAGEPATHMSG_H_*/
