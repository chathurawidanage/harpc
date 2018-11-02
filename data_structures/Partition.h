#ifndef UNTITLED_PARTITION_H
#define UNTITLED_PARTITION_H

#include <string>

namespace harp {
    namespace ds {
        template<class SAMPLE>
        class Partition {
        private:
            int id;
            SAMPLE* data;
        public:

            Partition(int id, SAMPLE* data);

            int getId();

            SAMPLE* getData();
        };
    }
}


#endif //UNTITLED_PARTITION_H