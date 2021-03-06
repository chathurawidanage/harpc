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
            long size = 0;
        public:

            Partition(int id, SAMPLE* data, long size);

            ~Partition();

            int getId();

            SAMPLE *getData();

            void setData(SAMPLE * data);

            long getSize();

            void clear();
        };

        enum PartitionState {
            ADDED, ADD_FAILED, COMBINED, COMBINE_FAILED
        };
    }
}


#endif //UNTITLED_PARTITION_H
