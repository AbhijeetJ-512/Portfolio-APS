# Version Control

Version control is a system that records a file change over time. That is, if multiple users are working on a single project, the system will manage and document revisions with which the users can retrieve any changes made.
These systems are essential to software development as they provide surety on the integrity of the code and enhance collaboration. This history of change management assists one to avoid cases of conflicts and missing data.

## SHA-1 Usage in Git

Git uses SHA-1, or Secure Hash Algorithm 1, intrinsic to its core functionality, to ensure that the data maintains integrity. That is what makes version control operations very efficient. In Git, every piece of data, whether it be a file, directory, or commit in this repository, is represented as a separate file identified by its own unique SHA-1 hash. The hash itself is computed based upon the content and type of the object, so it offers a good way of verifying data consistency across different repositories. When you make changes in Git, it calculates the SHA-1 hash of the commit—it will be a snapshot of a state of a repository. Using this hash, one is allowed to track changes and know which commit is a parent and which one is a child. Also, it has an ensured, verifiable history of modifications to the project.

Git uses SHA-1 not only for versioning but also for efficient data storage. It uses content-addressed storage. The same SHA-1 hash means that identical content will generate an identical hash across different commits or repositories, meaning there will be no redundant storage. Git further implements integrity with operations like Cloning, Fetching, Merging, and others because these processes make it recalculate the SHA-1 hash for each object and compare them to make sure no manipulation or corruption happens—chief security measures. While the insecurity of SHA-1 facing collision attacks has generally shifted cryptographic applications to stronger hash functions like SHA-256, it has so far not shifted in Git so much as for versioned data to lose its reliability and integrity.

Notwithstanding, SHA-1 is a deprecated algorithm, and since it is prone to a collision attack, vulnerability in a cryptographic context is not appropriate. Modern cryptographic practices encourage a switch to stronger hash functions like SHA-256 for maximum security and resistance to any further vulnerabilities.

![](./Images/hashing.png)

### Time & Space Complexity Analysis:

| Algorithm | Time Complexity |
|-----------|-----------------|
| SHA-1 | O(n), where n is the size of the input data |

| Algorithm | Space Complexity |
|-----------|------------------|
| SHA-1  | O(1), as SHA-1 produces a fixed-size output regardless of input size |

[Code for SHA-1 in python](../codes/sha_1.py)


## Directed Acyclic Graph (DAG) in Git

The DAG is central to the operation of Git. Every commit in Git has at least one parent commit, making it effectively a DAG with no cycles. This ensures an absolutely unambiguous and reviewable ancestry of changes, and allows developers to scroll through linear change history for a project with relative ease. Using the DAG, Git deals with branches, merges, and histories in a very efficient way; it's a really strong framework that serves its job of version control in an ultimate way.

Git uses a directed acyclic graph  but extends way beyond simple commits tracking to make efficient and high-speed complex operations like finding common ancestors of commits, graphical visualization of history of a project, simplicity in merging, and so forth. Git structures commits in a committed graph, therefore ensuring a correct and easily searchable history for a project. That ability to have branches is what gives Git and features like them meaning: multiple lines of development can happily proceed simultaneously without conflict.

![](./Images/DAG.png)

Git uses algorithms like Depth-First Search for browsing and manipulating the DAG. With this approach, Git can actually support O(V + E) operations, where V is the number of commits (vertices) and E is the number of parent-child relationships. There can't ever be conflicts, and at every point, each of the commits has its own unique, distinct history. This allows for collaborative development while keeping the purity of a project's timeline intact.

### Time & Space Complexity Analysis:

| Algorithm | Time Complexity |
|-----------|-----------------|
| Depth-First Search (DFS) for DAG | O(V + E), where V is the number of vertices (commits) and E is the number of edges (parent-child relationships)|

| Algorithm | Space Complexity |
|-----------|------------------|
|Depth-First Search (DFS) for DAG| O(V), where V is the number of vertices (commits), since additional space is needed for the visited array and the recursion stack |

[Code for DFS in C++](../codes/DFS.cpp)