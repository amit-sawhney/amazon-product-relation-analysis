<h1 align="center">
  CS 225 Final Project
  </br>
</h1>

<table align="center">
  <tr>
    <td align="center"><a href="https://www.linkedin.com/in/daniel-moon1/"><img src="./photos/daniel-moon.jpg" width="75px;" alt="Daniel Moon"/><br /><b>Daniel Moon</b></a><br /></td>
    <td align="center"><a href="https://www.linkedin.com/in/joseph-kuang-6bb55b1ba/"><img src="./photos/joseph-kuang.jpg" width="75px;" height="75px;" alt="Joseph Kuang"/><br /><b>Joseph Kuang</b></a><br /></td>
    <td align="center"><a href="https://github.com/ajain1921"><img src="./photos/aditya-jain.jpg" width="75px;" alt="Aditya Jain"/><br /><b>Aditya Jain</b></a><br /></td>
    <td align="center"><a href="https://www.linkedin.com/in/amit-m-sawhney/"><img src="./photos/amit-sawhney.jpg" width="75px;" height="75px;" alt="Amit Sawhney"/><br /><b>Amit Sawhney</b></a><br /></td>
    </tr>
</table>

<h4 align="center">Amazing CS 225 Project Group Minus Amit</h4>

<p align="center">
  <a href="#background-and-leading-question">Background and Leading Question</a> •
  <a href="#repository-breakdown">Repository Breakdown</a> •
  <a href="#technologies">Technologies</a> •
  <a href="#running-the-project">Running The Project</a> •
  <a href="#test-suite">Test Suite</a>
</p>

## Background and Leading Question

In our project, we are hoping to find some pattern between buying habits and how Amazon presents items that are frequently bought together. Specifically, we would like to explore the extent of importance of certain items, to see which items Amazon recommends together and if we can find any vertices that act as "hubs" for many items, meaning that it is more popular and bought with more other items. The final deliverable should rank these items by the number of items that are recommended with these "hub" nodes which reveals how likely it is to get from one place to another just through frequently bought together items.

The difference in the output we get from Betweenness Centrality and PageRank is that PageRank shows where all the edges lead to, while the Betweenness Centrality shows where all the shortests paths will go through as opposed to where they will end up.

[Full Proposal](https://github-dev.cs.illinois.edu/cs225-fa21/dm32-sawhney4-adityaj5-jjkuang2/blob/main/teamdocs/final_project_proposal.md)

## Repository Breakdown

- [Code](https://github-dev.cs.illinois.edu/cs225-fa21/dm32-sawhney4-adityaj5-jjkuang2/tree/main/src)
- [Data](https://github-dev.cs.illinois.edu/cs225-fa21/dm32-sawhney4-adityaj5-jjkuang2/tree/main/data)
- [Tests](https://github-dev.cs.illinois.edu/cs225-fa21/dm32-sawhney4-adityaj5-jjkuang2/tree/main/tests)
- [Results](https://github-dev.cs.illinois.edu/cs225-fa21/dm32-sawhney4-adityaj5-jjkuang2/tree/main/results)

### Configuring Data

Due to the size the data, please download the Amazon [dataset](http://snap.stanford.edu/data/amazon0302.html) and follow the instructions below.

1. Download the [dataset](http://snap.stanford.edu/data/amazon0302.html).
2. Extract the data into a file called `data.txt`. 
3. Drop the data into the `data/` directory.  

## Technologies

<table align="center">
  <tr>
    <td align="center"><a href="https://en.cppreference.com/w/"><img src="https://upload.wikimedia.org/wikipedia/commons/thumb/1/18/ISO_C%2B%2B_Logo.svg/1822px-ISO_C%2B%2B_Logo.svg.png" width="75px;" alt="C++"/><br /><b>C++</b></a></td>
    <td align="center"><a href="https://www.gnu.org/software/make/manual/make.html"><img src="https://www.iconattitude.com/icons/open_icon_library/crystal-style/png/256/text-x-makefile.png" width="75px;" height="85px;" alt="Makefile"/><br /><b>Makefile</b></a></td>
    <td align="center"><a href="https://github.com/catchorg/Catch2"><img src="https://raw.githubusercontent.com/catchorg/Catch2/devel/data/artwork/catch2-logo-small.png?sanitize=false" width="150px;" height="85px" alt="Catch2"/><br /><b>Catch2</b></a></td>
    </tr>
</table>

## Running the Project

### Prerequisites

- Please make sure you have configured the data as mentioned above if you would like to run main code.
- Ensure that you are in the [root](https://github-dev.cs.illinois.edu/cs225-fa21/dm32-sawhney4-adityaj5-jjkuang2) directory. 

### Main 

```bash
make all
```

```bash
make
```

### Tests

```bash
make test
```
#### Argument Example
```bash
make test [spring=0]
```
#### Available Arguments
- `spring=0`
- `spring=1`
- `dfs`
- `pagerank`
- `betweencentrality`

### Choosing Input File and Output Location
- `make {input} {output}`

### Cleaning Directory

```bash
make clean
```

## Test Suite
