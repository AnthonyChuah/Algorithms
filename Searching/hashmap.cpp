// Int to int hash map.

struct Entry {
  bool used;
  bool deleted;
  int key;
  int value;
};

class HashMap {
public:
  HashMap() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
      entries[i].used = false; entries[i].deleted = false;
    }
  }
  static unsigned int key_hasher(const int key) {
    unsigned int hashed = 0;
    if (key < 0) {
      key *= -1;
    }
    hashed = key % TABLE_SIZE;
  }
  Entry* lookup_skip_deleted(const int key) const {
    unsigned int index = key_hasher(key);
    std::cout << "Key " << key << " hashed to: " << index << ".\n";
    Entry* e;
    for (int i = 0; i < TABLE_SIZE; ++i) {
      e = &entries[index];
      if (e->used) {
	if (e->key == key) {
	  std::cout << "Found a key match. Returning the corresponding value.\n";
	  return e;
	} else {
	  std::cout << "Hash collision: index " << index << " is in use. Probe past.\n";
	}
      } else if (e->deleted) {
	std::cout << "Open addressing collision: index " << index << " is a deleted entry. Probe past.\n";
      } else {
	std::cout << "Found a never-been-used entry.\n";
	return e;
      }
      std::cout << "Increment index " << index << " by 1, modulo table size, new index: ";
      index = ++index % TABLE_SIZE;
      std::cout << index << ".\n";
    }
    return nullptr; // HashMap is completely full!
  }
  Entry* lookup(const int key) const {
    unsigned int index = key_hasher(key);
    std::cout << "Key " << key << " hashed to: " << index << ".\n";
    Entry* e;
    for (int i = 0; i < TABLE_SIZE; ++i) {
      e = &entries[index];
      if (e->used) {
	if (e->key == key) {
	  std::cout << "Found a key match. Returning the corresponding value.\n";
	  return e;
	} else {
	  std::cout << "Hash collision: index " << index << " is in use. Probe past.\n";
	}
      } else if (e->deleted) {
	std::cout << "Open addressing collision: index " << index << " is a deleted entry. Use this entry.\n";
	return e;
      } else {
	std::cout << "Found a never-been-used entry.\n";
	return e;
      }
      std::cout << "Increment index " << index << " by 1, modulo table size, new index: ";
      index = ++index % TABLE_SIZE;
      std::cout << index << ".\n";
    }
    return nullptr; // HashMap is completely full!
  }
  bool add(const int key, const int value) {
    Entry* entry = lookup(key);
    bool new_entry = true;
    if (entry->used = true) {
      std::cout << "Attempted to add to an existing entry. Overwriting!\n";
      new_entry = false;;
    }
    entry->used = true;
    entry->deleted = false;
    entry->key = key;
    entry->value = value;
    return new_entry;
  }
  int find_by_key(const int key) const {
    Entry* entry = lookup_skip_deleted(key);
    if (entry == nullptr) {
      std::cout << "Could not find the corresponding Entry for key " << key << "!\n";
    } else {
      std::cout << "Found corresponding Entry for key " << key << ".\n";
    }
    return entry->value;
  }
  bool erase(const int key) {
    Entry* entry = lookup_skip_deleted(key);
    if (entry == nullptr) {
      std::cout << "Could not find the corresponding Entry to delete, for key " << key << "!\n";
      return false;
    }
    entry->used = false;
    entry->deleted = true;
    return true;
  }
private:
  Entry entries[TABLE_SIZE];
};
