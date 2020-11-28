#include<stdio.h>
#define NONE -1

enum _figure {Line = 1, Rectangle = 2, Circle = 3};

struct figure {
  int id;
  int name;
  int p1_x;
  int p1_y;
  int p2_x; 
  int p2_y;
  int r1;
};
void initDatabase(struct figure database[], int num) {
  for(int i = 0; i < num; i++) {
    database[i].id = NONE;
  }
};

struct figure addFigure() {
  enum _figure name;
  struct figure new;
  int input;
  printf("Enter the figure id: ");
  scanf(" %d", &new.id);
  printf("Enter the shape (1: Line, 2: Rect, 3: Circle): ");
  scanf(" %d", &input);
  switch(input) {
    case 1:
      name = Line;
      new.name = name;
      printf("Enter the (r,c) coordinate of P1: ");
      scanf(" %d %d", &new.p1_x, &new.p1_y);
      printf("Enter the (r,c) coordinate of P2: ");
      scanf(" %d %d", &new.p2_x, &new.p2_y);
      printf("Line (id: %d) from (%d,%d) to (%d,%d) is added.\n\n", new.id, new.p1_x, new.p1_y, new.p2_x, new.p2_y);
      new.r1 = NONE;
      return new;

    case 2:
      name = Rectangle;
      new.name = name;
      printf("Enter the (r,c) coordinate of P1: ");
      scanf(" %d %d", &new.p1_x, &new.p1_y);
      printf("Enter the (r,c) coordinate of P2: ");
      scanf(" %d %d", &new.p2_x, &new.p2_y);
      printf("Rectangle (id: %d) from (%d,%d) to (%d,%d) is added.\n\n", new.id, new.p1_x, new.p1_y, new.p2_x, new.p2_y);
      new.r1 = NONE;
      return new;

    case 3:
      name = Circle;
      new.name = name;
      printf("Enter the (r,c) coordinate of P1: ");
      scanf(" %d %d", &new.p1_x, &new.p1_y);
      printf("Enter the R1: ");
      scanf(" %d", &new.r1);   
      printf("Circle (id: %d) with the center (%d,%d) and the radius (%d) is added.\n\n", new.id, new.p1_x, new.p1_y, new.r1);
      new.p2_x = NONE;
      new.p2_y = NONE;
      return new;
  }
};

void removeFigure(struct figure database[], int num) {
  int removeId;
  printf("Enter the figure id: ");
  scanf(" %d", &removeId);
  switch (database[removeId].name) {
      case 1:
        printf("Line (id: %d) from (%d,%d) to (%d, %d) is removed.\n\n", database[removeId].id, database[removeId].p1_x, database[removeId].p1_y, database[removeId].p2_x, database[removeId].p2_y);
        break;
      case 2:
        printf("Rectangle (id: %d) from (%d,%d) to (%d, %d) is removed.\n\n", database[removeId].id, database[removeId].p1_x, database[removeId].p1_y, database[removeId].p2_x, database[removeId].p2_y);
        break;
      case 3:
        printf("Circle (id: %d) with the center (%d,%d) and the radius (%d) is removed\n\n", database[removeId].id, database[removeId].p1_x, database[removeId].p1_y, database[removeId].r1);
        break;
    }
  database[removeId].id = NONE;
};

struct figure adjustFigure(struct figure database[], int num) {
  int id;
  printf("Enter the figure id: ");
  scanf(" %d", &id);
  switch(database[id].name) {
    case 1:
      printf("Enter the (r,c) coordinate of P1: ");
      scanf(" %d %d", &database[id].p1_x, &database[id].p1_y);
      printf("Enter the (r,c) coordinate of P2: ");
      scanf(" %d %d", &database[id].p2_x, &database[id].p2_y);
      printf("Line (id: %d) from (%d,%d) to (%d,%d) is adjusted.\n\n", database[id].id, database[id].p1_x, database[id].p1_y, database[id].p2_x, database[id].p2_y);
      break;
    case 2:
      printf("Enter the (r,c) coordinate of P1: ");
      scanf(" %d %d", &database[id].p1_x, &database[id].p1_y);
      printf("Enter the (r,c) coordinate of P2: ");
      scanf(" %d %d", &database[id].p2_x, &database[id].p2_y);
      printf("Rectangle (id: %d) from (%d,%d) to (%d,%d) is adjusted.\n\n", database[id].id, database[id].p1_x, database[id].p1_y, database[id].p2_x, database[id].p2_y);
      break;
    case 3:
      printf("Enter the (r,c) coordinate of P1: ");
      scanf(" %d %d", &database[id].p1_x, &database[id].p1_y);
      printf("Enter the R1: ");
      scanf(" %d", &database[id].r1);
      printf("Circle (id: %d) with the center (%d,%d) and the radius (%d) is added.\n\n", database[id].id, database[id].p1_x, database[id].p1_y, database[id].r1);
      break;
  }
};

void printFigure(struct figure database[], int num, int max) {
  for(int i = 0; i <= max; i++) {
    if(database[i].id == NONE) continue;
    switch (database[i].name) {
      case 1:
        printf("Line (id: %d) from (%d,%d) to (%d, %d).\n", database[i].id, database[i].p1_x, database[i].p1_y, database[i].p2_x, database[i].p2_y);
        break;
      case 2:
        printf("Rectangle (id: %d) from (%d,%d) to (%d, %d).\n", database[i].id, database[i].p1_x, database[i].p1_y, database[i].p2_x, database[i].p2_y);
        break;
      case 3:
        printf("Circle (id: %d) with the center (%d,%d) and the radius (%d)\n", database[i].id, database[i].p1_x, database[i].p1_y, database[i].r1);
        break;
    }
  }
  printf("\n");
};

int main() {
  struct figure temp;
  struct figure data[100];
  int command;
  int maxId = 0;
  initDatabase(data, 100);

  for(;;) {
    printf("Enter a command (1: Add, 2:Remove, 3: Ajdust, 4:Export, 5:Print, 0:Exit): ");
    scanf(" %d", &command);
    switch(command) {
      case 1:
        temp = addFigure();
        data[temp.id] = temp;
        if(maxId < temp.id) maxId = temp.id;
        break;
      case 2:
        removeFigure(data, 100);
        break;
      case 3:
        break;
      case 4:
        break;
      case 5:
        printFigure(data, 100, maxId);
        break;
    }
  }  
}