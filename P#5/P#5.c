#include<stdio.h>
#include<math.h>

#define NONE -1
#define DATASIZE 100
#define CANVAS_R 200
#define CANVAS_C 200

char canvas[CANVAS_R][CANVAS_C];

enum _figure {Line = 1, Rectangle = 2, Circle = 3};

struct figure {
  int id;
  int name;
  int p1_r;
  int p1_c;
  int p2_r;
  int p2_c;
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
      scanf(" %d %d", &new.p1_r, &new.p1_c);
      printf("Enter the (r,c) coordinate of P2: ");
      scanf(" %d %d", &new.p2_r, &new.p2_c);
      printf("Line (id: %d) from (%d,%d) to (%d,%d) is added.\n\n", new.id, new.p1_r, new.p1_c, new.p2_r, new.p2_c);
      new.r1 = NONE;
      return new;

    case 2:
      name = Rectangle;
      new.name = name;
      printf("Enter the (r,c) coordinate of P1: ");
      scanf(" %d %d", &new.p1_r, &new.p1_c);
      printf("Enter the (r,c) coordinate of P2: ");
      scanf(" %d %d", &new.p2_r, &new.p2_c);
      printf("Rectangle (id: %d) from (%d,%d) to (%d,%d) is added.\n\n", new.id, new.p1_r, new.p1_c, new.p2_r, new.p2_c);
      new.r1 = NONE;
      return new;

    case 3:
      name = Circle;
      new.name = name;
      printf("Enter the (r,c) coordinate of P1: ");
      scanf(" %d %d", &new.p1_r, &new.p1_c);
      printf("Enter the R1: ");
      scanf(" %d", &new.r1);
      printf("Circle (id: %d) with the center (%d,%d) and the radius (%d) is added.\n\n", new.id, new.p1_r, new.p1_c, new.r1);
      new.p2_r = NONE;
      new.p2_c = NONE;
      return new;
  }
  return new;
}

int removeFigure(struct figure database[], int num) {
  int removeId;
  printf("Enter the figure id: ");
  scanf(" %d", &removeId);
  switch (database[removeId].name) {
    case 1:
      printf("Line (id: %d) from (%d,%d) to (%d, %d) is removed.\n\n", database[removeId].id, database[removeId].p1_r, database[removeId].p1_c, database[removeId].p2_r, database[removeId].p2_c);
      break;
    case 2:
      printf("Rectangle (id: %d) from (%d,%d) to (%d, %d) is removed.\n\n", database[removeId].id, database[removeId].p1_r, database[removeId].p1_c, database[removeId].p2_r, database[removeId].p2_c);
      break;
    case 3:
      printf("Circle (id: %d) with the center (%d,%d) and the radius (%d) is removed\n\n", database[removeId].id, database[removeId].p1_r, database[removeId].p1_c, database[removeId].r1);
      break;
  }
  database[removeId].id = NONE;
  return removeId;
};

void adjustFigure(struct figure database[], int num) {
  int id;
  printf("Enter the figure id: ");
  scanf(" %d", &id);
  switch(database[id].name) {
    case 1:
      printf("Enter the (r,c) coordinate of P1: ");
      scanf(" %d %d", &database[id].p1_r, &database[id].p1_c);
      printf("Enter the (r,c) coordinate of P2: ");
      scanf(" %d %d", &database[id].p2_r, &database[id].p2_c);
      printf("Line (id: %d) from (%d,%d) to (%d,%d) is adjusted.\n\n", database[id].id, database[id].p1_r, database[id].p1_c, database[id].p2_r, database[id].p2_c);
      break;
    case 2:
      printf("Enter the (r,c) coordinate of P1: ");
      scanf(" %d %d", &database[id].p1_r, &database[id].p1_c);
      printf("Enter the (r,c) coordinate of P2: ");
      scanf(" %d %d", &database[id].p2_r, &database[id].p2_c);
      printf("Rectangle (id: %d) from (%d,%d) to (%d,%d) is adjusted.\n\n", database[id].id, database[id].p1_r, database[id].p1_c, database[id].p2_r, database[id].p2_c);
      break;
    case 3:
      printf("Enter the (r,c) coordinate of P1: ");
      scanf(" %d %d", &database[id].p1_r, &database[id].p1_c);
      printf("Enter the R1: ");
      scanf(" %d", &database[id].r1);
      printf("Circle (id: %d) with the center (%d,%d) and the radius (%d) is added.\n\n", database[id].id, database[id].p1_r, database[id].p1_c, database[id].r1);
      break;
  }
}

void printFigure(struct figure database[], int num, int max) {
  for(int i = 0; i <= max; i++) {
    if(database[i].id == NONE) continue;
    switch (database[i].name) {
      case 1:
        printf("Line (id: %d) from (%d,%d) to (%d, %d).\n", database[i].id, database[i].p1_r, database[i].p1_c, database[i].p2_r, database[i].p2_c);
        break;
      case 2:
        printf("Rectangle (id: %d) from (%d,%d) to (%d, %d).\n", database[i].id, database[i].p1_r, database[i].p1_c, database[i].p2_r, database[i].p2_c);
        break;
      case 3:
        printf("Circle (id: %d) with the center (%d,%d) and the radius (%d)\n", database[i].id, database[i].p1_r, database[i].p1_c, database[i].r1);
        break;
    }
  }
  printf("\n");
};

void initCanvas() {
  for(int i = 0; i < 200; i++ ) {
    for(int j = 0; j < 200; j++) {
      canvas[i][j] = ' ';
    }
  }
}

void makeLine(struct figure data) {  
  // r이랑 c값 정리  
  float m = (float)(data.p2_r - data.p1_r) / (data.p2_c - data.p1_c);
  m = fabs(m);
  int n = -m*data.p1_c + data.p1_r;
  canvas[data.p1_r][data.p1_c] = '*';
  int delC = abs(data.p1_c - data.p2_c);
  int delR = abs(data.p1_r - data.p2_r);
  if(delC == 0 ){
    for(int i = 0; i < delR; i ++) {
      data.p1_r++;
      canvas[data.p1_r][data.p1_c] = '*';
    }
  }
  if(m >= 1) {
    int p = 2 * delC - delR;
    for(int i = 0; i < delC; i++) {
      if(p < 0) {
        data.p1_r++;
        canvas[data.p1_r][data.p1_c] = '*';
        p = p+(2*delC);
      } else {
        data.p1_c++;
        data.p1_r++;
        canvas[data.p1_r][data.p1_c] = '*';
        p = p+(2*delC) - (2*delR);
      }
    }
  } else if(m < 1) {
    int p = 2 * delR - delC;
    for(int i = 0; i< delC; i++) {
      if(p < 0) {
        data.p1_c++;
        canvas[data.p1_r][data.p1_c] = '*';
        p = p + (2 * delR);
      } else {
        data.p1_c++;
        data.p1_r++;
        canvas[data.p1_r][data.p1_c] = '*';
        p = p + (2 * delR) - (2 * delC);
      }
    }
  }
}

void makeRectangle(struct figure data) {
  struct figure line1, line2, line3, line4;  
  // point1 -> point 2
  line1.p1_c = data.p1_c;
  line1.p1_r = data.p1_r;
  line1.p2_c = data.p2_c;
  line1.p2_r = data.p1_r;
  // point 1 -> point 3
  line2.p1_c = data.p1_c;
  line2.p1_r = data.p1_r;
  line2.p2_c = data.p1_c;
  line2.p2_r = data.p2_r;
  // point 2 -> point4
  line3.p1_c = data.p2_c;
  line3.p1_r = data.p1_r;
  line3.p2_c = data.p2_c;
  line3.p2_r = data.p2_r;
  // point 3 -> point4
  line4.p1_c = data.p1_c;
  line4.p1_r = data.p2_r;
  line4.p2_c = data.p2_c;
  line4.p2_r = data.p2_r;
  makeLine(line1);
  makeLine(line2);
  makeLine(line3);
  makeLine(line4);
}

void makeCircle(struct figure data) {
  int c_centre, r_centre, radius;
  c_centre = data.p1_c;
  r_centre = data.p1_r;
  radius = data.r1;

  int c = radius, r = 0;

    // Printing the initial point on the axes
    // after translation
    canvas[c + c_centre][r + r_centre] = '*';

    // When radius is zero only a single
    // point will be printed
    if (radius > 0)
    {
        canvas[c + c_centre][-r + r_centre] = '*';
        canvas[r + c_centre][c + r_centre] = '*';
        canvas[-r + c_centre][-c + r_centre] = '*';
        canvas[-c + c_centre][-r + r_centre] = '*';
    }

    // Initialising the value of P
    int P = 1 - radius;
    while (c > r)
    {
        r++;

        // Mid-point is inside or on the perimeter
        if (P <= 0)
            P = P + 2*r + 1;

        // Mid-point is outside the perimeter
        else
        {
            c--;
            P = P + 2*r - 2*c + 1;
        }

        // All the perimeter points have already been printed
        if (c < r)
            break;

        // Printing the generated point and its reflection
        // in the other octants after translation

        canvas[c + c_centre][r + r_centre] = '*';
        canvas[-c + c_centre][r + r_centre] = '*';
        canvas[c + c_centre][-r + r_centre] = '*';
        canvas[-c + c_centre][-r + r_centre] = '*';

        // If the generated point is on the line x = y then
        // the perimeter points have already been printed
        if (c != r)
        {
            canvas[r + c_centre][c + r_centre] = '*';
            canvas[-r + c_centre][c + r_centre] = '*';
            canvas[r + c_centre][-c + r_centre] = '*';
            canvas[-r + c_centre][-c + r_centre] = '*';
        }
    }
}

void makeFile() {
  FILE *txt = fopen("print.txt", "w");

  if(txt == NULL) {
    printf("ERROR: File open error");
    return;
  }
  for(int r = 0; r < CANVAS_R; r++) {
    for(int c = 0; c < CANVAS_C; c++) {
      fputc(canvas[r][c], txt);  
    }
    fputc('\n', txt);
  }

}

void exportFigure(struct figure database[], int num, int max) {
  initCanvas();
  for(int dataIndex = 0; dataIndex <= max; dataIndex++) {
    struct figure data = database[dataIndex];
    if(data.id == NONE) continue;
    switch(data.name) {
      case 1:
        makeLine(data);
        break;
      case 2:
        makeRectangle(data);
        break;
      case 3:
        makeCircle(data);
        break;
    }    
  }
  // file
  makeFile();
  for(int i =0; i< 20; i++) {
    for(int j =0; j < 20; j++){
      printf("%c",canvas[i][j]);
    }
    printf("\n");
  }
}

int main() {
  struct figure temp;
  struct figure data[DATASIZE];
  int command, removed;
  int maxId = 0;
  initDatabase(data, DATASIZE);

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
        removed = removeFigure(data, DATASIZE);
        if(removed == maxId) {
          for(int i = maxId; i > 0;i--) {
            if(data[i].id != NONE) {
              maxId = i;
              break;
            }
          }
        }
        break;
      case 3:
        adjustFigure(data, DATASIZE);
        break;
      case 4:
        exportFigure(data, DATASIZE, maxId);
        break;
      case 5:
        printFigure(data, DATASIZE, maxId);
        break;
      default:
      return 0;
    }


  }
}


