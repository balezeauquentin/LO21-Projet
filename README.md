# Evolutionary Simulation in C

## Overview

Welcome to the Evolutionary Simulation project! This C-based simulation explores the fascinating dynamics of evolution within a population. The core idea revolves around the selection of the best individuals in each generation, from whom a new generation is crafted.

## Features

- **Population Evolution:** Witness the evolution of a population over a customizable number of generations.

- **Bit Representation:** Each individual in the population is represented by a set of bits, and their overall value is determined by a sophisticated equation.

- **Selective Breeding:** The best individuals from each generation are carefully chosen to form the foundation for the next generation, mirroring natural selection.

- **Customizable Parameters:** Tailor the simulation to your liking with adjustable parameters such as the number of generations and criteria for selecting the best individuals.

## Project Structure

- **Individu.c & Individu.h:** Files defining the structure and functionalities of an individual in the population.

- **Population.c & Population.h:** Files governing the overall population dynamics, including the evolution process.

- **liste_bit.c & liste_bit.h:** Files handling the bit representation of individuals and related operations.

- **main.c:** The main file orchestrating the entire simulation.

## Getting Started

1. Clone the repository to your local machine.

   ```bash
   git clone https://github.com/balezeauquentin/LO21-projet.git
   ```

3. Compile the project.

   For Unix Users.
   ```bash
   make
   ```

   For Windows Users.
   ```bash
   make
   ```
   

5. Run the simulation.

   ```bash
   ./evolution_simulation
   ```

## Customization

Feel free to tweak the parameters in the `main.c` file to experiment with different scenarios. Adjust the number of generations, criteria for selection, and equation determining individual values.

## Acknowledgments

This project is a testament to the beauty of evolution and the power of selective processes. Special thanks to the contributors and the C community for making this simulation possible.

Happy evolving! 🌱🧬
