#include "Table.h"

namespace harp {
    namespace ds {
        template<class TYPE>
        Table<TYPE>::Table(int id) {
            this->id = id;
        }

        template<class TYPE>
        int Table<TYPE>::getId() {
            return this->id;
        }

        template<class TYPE>
        long Table<TYPE>::getPartitionCount() {
            return this->partitionMap.size();
        }

        template<class TYPE>
        std::map<int, Partition<TYPE> *> Table<TYPE>::getPartitions() {
            return this->partitionMap;
        }

        template<class TYPE>
        PartitionState Table<TYPE>::addPartition(Partition<TYPE> *partition) {
            this->partitionMap.insert(std::make_pair(partition->getId(), partition));
            return COMBINED;
        }

        template<class TYPE>
        Partition<TYPE> *Table<TYPE>::getPartition(int pid) {
            return this->partitionMap.at(pid);
        }

        template<class TYPE>
        long Table<TYPE>::removePartition(int pid, bool clearMemory) {
            if (this->partitionMap.count(pid) > 0) {
                if (clearMemory) {
                    delete this->getPartition(pid);
                }
                return this->partitionMap.erase(pid);//remove from map
            } else {
                return 0;
            }
        }

        template<class TYPE>
        void Table<TYPE>::clear() {
            for (auto p: this->partitionMap) {
                delete p.second;
            }
            this->partitionMap.clear();
        }

        template<class TYPE>
        Table<TYPE>::~Table() {
            this->clear();
        }

        template<class TYPE>
        void Table<TYPE>::replaceParition(int pid, Partition<TYPE> *partition) {
            this->removePartition(pid);
            this->addPartition(partition);
        }
    }
}