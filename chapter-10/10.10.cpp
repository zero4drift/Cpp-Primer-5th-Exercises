// Algorithm operates on iterators, it could change the value pointed by iterator(if it is not const iterator), but it is not capable of deleting or inserting, which are functions based on container itself(container.erase(...), container.inser(...)...).