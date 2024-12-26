# ELK ILM and Important Terms Definitions

- ILM stands for index Lifetime management. These are important concepts when dealing with log management to keep space efficiency.

- There are several (lifetime) level defined in elasticsearch:
    - Hot (fresh logs): Need to define when to `rollover` to a new index
    - Warm (recent logs): define when to compress or merge log files to save space but keep them accessible
    - Cold (old logs): optional, similar to warm. Can do more data archive or migration stuffs.
    - Delete: define when to delete out-of-date logs
- First of all, need to understand the terms used in log managing. Using the analogy of a modern digital library to Elasticsearch.

1. Data Stream
A `Data stream` is like a continuous feed of books arriving at the library. 
For example, your nginx access logs and error logs are continuously flowing in , creating new records over time. Instead of storing all books(logs) in one giant room, we organize them into smaller, manageable sections.

2. Index
An `index` is like a single bookshelf in the library. It has a specific organization system and holds a set of related documents.
For example, `nginx-access-000001` is one index, containing all nginx access logs from a specific period.

3. Indices (plural of index)
`Indices` are like having multiple bookshelves. As your logs grow from the time being, you create new indices (new bookshelves) to store them efficiently.
For example, `nginx-access-000002` could be a second bookshelf once the previous one is full.
This is why the index-patterns are like `nginx-access-*` to refer to all related indices.

4. Alias
An `alias` is like a sign pointing to one or more bookshelves. It's a virtual name that can point to one or more indices. There are two important types of aliases:
    1. A `write alias` is like having a "Current Books" sign that always points to the newest bookshelf. Only one index can be the write index at a time.
    2. A `read alias` is like having a "Historical Books" sign that can point to multiple bookshelves for searching.

- In order to apply "rollover", we need to use an `write alias` as a pointer to notify which bookshelf (index) we are targeting right now. Once it reaches to certain conditions (by how long or the size), we will have to "rollover" and create a new index.
