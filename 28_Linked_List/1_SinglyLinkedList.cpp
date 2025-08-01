
// ### 📦 1. **Array**

// * **Size**: Fixed at creation.
// * **Memory**: Contiguous block.
// * **Access (get/set)**: 🔥 Fast – O(1)
// * **Insert/Delete**: ❌ Slow – O(n) (shifting needed)
// * **Thread-Safe**: ❌ No
// * **Use Case**: When size is known and random access is frequent.

// ---

// ### 🔗 2. **LinkedList**

// * **Size**: Dynamic (grows/shrinks easily).
// * **Memory**: Non-contiguous (each node stores data + reference).
// * **Access (get/set)**: ❌ Slow – O(n)
// * **Insert/Delete**: ✅ Fast – O(1) (if pointer is known)
// * **Thread-Safe**: ❌ No
// * **Use Case**: Frequent insertion/deletion, not much random access.

// ---

// ### 📑 3. **Vector**

// * **Size**: Dynamic (like ArrayList but grows by 2x).
// * **Memory**: Contiguous block.
// * **Access (get/set)**: 🔥 Fast – O(1)
// * **Insert/Delete**: ❌ Slow – O(n)
// * **Thread-Safe**: ✅ Yes (synchronized methods)
// * **Use Case**: Legacy code or when thread-safety is needed.

// ---

// ### 🔍 Summary Table:

// | Feature       | Array     | LinkedList | Vector    |
// | ------------- | --------- | ---------- | --------- |
// | Size          | Fixed     | Dynamic    | Dynamic   |
// | Access Speed  | Fast O(1) | Slow O(n)  | Fast O(1) |
// | Insert/Delete | Slow O(n) | Fast O(1)  | Slow O(n) |
// | Thread-Safe   | No        | No         | Yes       |
// | Memory        | Efficient | More usage | Efficient |

// ---

// ### ✅ When to Use:

// * **Array**: Use for performance + fixed-size data (e.g., matrix, lookup table).
// * **LinkedList**: Use for frequent inserts/deletes (e.g., queues, undo operations).
// * **Vector**: Use if you need a thread-safe dynamic array, though it's outdated (prefer `Collections.synchronizedList(new ArrayList<>())` now).
