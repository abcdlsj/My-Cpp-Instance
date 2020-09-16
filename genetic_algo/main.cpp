#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

const std::string Target = "I love LSJ!";
const int PopSize = 200;
const double MutationRate = 0.005;

struct Organism {
  std::string DNA;
  double Fitness;
};

Organism createOrganism(std::string target);
std::vector<Organism> creatPopulation(std::string target);
void calcFitness(Organism &organism);
std::vector<Organism> creatPool(std::vector<Organism> population,
                                double maxFitness);
std::vector<Organism> naturalSelection(std::vector<Organism> pool,
                                       std::vector<Organism> population);
Organism crossover(Organism f1, Organism f2);
void mutate(Organism &organism);
Organism getBest(std::vector<Organism> population);

// 生成个体
Organism createOrganism(std::string target) {
  std::string ba(target);
  for (int i = 0; i < target.size(); i++) {
    ba[i] = rand() % 32 + 95;
  }
  Organism newOrganism;
  newOrganism.DNA = ba;
  newOrganism.Fitness = 0;
  calcFitness(newOrganism);
  return newOrganism;
}

std::vector<Organism> creatPopulation(std::string target) {
  std::vector<Organism> population;

  for (int i = 0; i < PopSize; i++) {
    population.push_back(createOrganism(Target));
  }

  return population;
}

void calcFitness(Organism &organism) {
  int score = 0;

  for (int i = 0; i < Target.size(); i++) {
    if (organism.DNA[i] == Target[i]) {
      score++;
    }
  }
  organism.Fitness = (double)score / (double)Target.size();
  return;
}

std::vector<Organism> creatPool(std::vector<Organism> population,
                                double maxFitness) {
  std::vector<Organism> pool;
  for (int i = 0; i < population.size(); i++) {
    int num = (int)((population[i].Fitness / maxFitness) * 100);
    for (int j = 0; j < num; j++) {
      pool.push_back(population[i]);
    }
  }

  return pool;
}

std::vector<Organism> naturalSelection(std::vector<Organism> pool,
                                       std::vector<Organism> population) {
  std::vector<Organism> next;
  for (int i = 0; i < population.size(); i++) {
    int idx1 = rand() % pool.size(), idx2 = rand() % pool.size();

    Organism f1 = pool[idx1], f2 = pool[idx2];

    Organism child = crossover(f1, f2);
    mutate(child);
    calcFitness(child);
  }
  return next;
}

Organism crossover(Organism f1, Organism f2) {
  Organism des;
  int mid = rand() % f1.DNA.size();

  for (int i = 0; i < f1.DNA.size(); i++) {
    if (i > mid) {
      des.DNA[i] = f1.DNA[i];
    } else {
      des.DNA[i] = f2.DNA[i];
    }
  }
  return des;
}

void mutate(Organism &organism) {
  for (int i = 0; i < organism.DNA.size(); i++) {
    if (((double)(rand() % 100)) / 100 < MutationRate) {
      organism.DNA[i] = rand() % 32 + 95;
    }
  }
  return;
}

Organism getBest(std::vector<Organism> population) {
  double bestFitness = population[0].Fitness;
  int bestIdx = 0;
  for (int i = 0; i < population.size(); i++) {
    if (population[i].Fitness > bestFitness) {
      bestFitness = population[i].Fitness;
      bestIdx = i;
    }
  }
  return population[bestIdx];
}

int main() {
  std::vector<Organism> population = creatPopulation(Target);
  bool found = false;
  int generation = 0;

  while (!found) {
    generation++;
    Organism BestOrganism;
    BestOrganism = getBest(population);
    printf("eneration: %d | %s | fitness: %6f", generation,
           BestOrganism.DNA.c_str(), BestOrganism.Fitness);
    if (BestOrganism.DNA == Target) {
      found = true;
    } else {
      double maxFitness = BestOrganism.Fitness;
      std::vector<Organism> pool = creatPool(population, maxFitness);
      population = naturalSelection(pool, population);
    }
  }
  printf("find it");
}