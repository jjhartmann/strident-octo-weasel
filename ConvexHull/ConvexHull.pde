import java.util.Comparator; //<>// //<>//

ArrayList<PVector> pointSet;
ArrayList<PVector> hullSetU;
ArrayList<PVector> hullSetL;

boolean drawHullU = false;
boolean drawHullL = false;

void setup() {
  size(800, 600);
  hullSetU = new ArrayList<PVector>();
  hullSetL = new ArrayList<PVector>();
  pointSet = new ArrayList<PVector>(20);
  for (int i = 0; i < 20; ++i) {
    pointSet.add(new PVector());
  }

  createRandomPointSet();
}

void draw() {
  background(200);
  drawRandomPointSet();
  
  if (drawHullU) {
    drawConvexHullU();
  }
  if (drawHullL) {
    drawConvexHullL();
  }
}

void drawRandomPointSet() {
  noStroke();
  fill(0);
  for (int i = 0; i < 20; ++i) {
    ellipse(pointSet.get(i).x, pointSet.get(i).y, 10, 10);
  }
}

void createRandomPointSet() {
  for (PVector p : pointSet) {
    float x = random(width);// (randomGaussian() * width/9) + width/2;
    float y = random(height);//(randomGaussian() * height/9) + height/2;
    p.x = round(x);
    p.y = round(y);
  }
  
  hullSetU.clear();
  hullSetL.clear();
  computeConvexHull();
}

// Compute the convex Hull
void computeConvexHull() {
  // Sort Point Set
  pointSet.sort(new SortByXCord()); //<>// //<>//
  int size = pointSet.size();
  
  hullSetU.add(pointSet.get(0));
  hullSetU.add(pointSet.get(1));
  int j = hullSetU.size() -1;

  // Iterate through point set in order to build hull
  for (int i = 2; i < size; ++i) {
    hullSetU.add(pointSet.get(i));
    ++j;

    while ( j >= 2 && checkCrossProduct(hullSetU.get(j), hullSetU.get(j - 1), hullSetU.get(j - 2))) {
      hullSetU.remove(j-1);  
      --j;
    }
  }

  // Iterate throw lower halve
  hullSetL.add(pointSet.get(size - 1));
  hullSetL.add(pointSet.get(size - 2));
  int k = hullSetL.size() - 1;
  
  for (int i = size - 1; i >= 0; --i) {
    hullSetL.add(pointSet.get(i));
    ++k;

    while ( k >= 2 && checkCrossProduct(hullSetL.get(k), hullSetL.get(k - 1), hullSetL.get(k - 2))) {
      hullSetL.remove(k-1);  
      --k;
    }
  }
}

float dRes = 0;
// Calculate cross product and determine left turns (Positive Angle)
boolean checkCrossProduct(PVector p1, PVector p2, PVector p3) {
  dRes = ((p2.x - p1.x)*(p3.y - p1.y)) - ((p2.y - p1.y)*(p3.x - p1.x));
  return ((p2.x - p1.x)*(p3.y - p1.y)) - ((p2.y - p1.y)*(p3.x - p1.x)) >= 0;
}


// Draw Convex Hull
void drawConvexHullU() {
  int size = hullSetU.size();
  for(int i = 0; i < size - 1; ++i) {
    PVector b = hullSetU.get(i % size);
    PVector e = hullSetU.get((i + 1) % size);
    stroke(0);
    line(b.x, b.y, e.x, e.y); 
  }
}
void drawConvexHullL() {
  int size = hullSetL.size();
  for(int i = 0; i < size - 1; ++i) {
    PVector b = hullSetL.get(i % size);
    PVector e = hullSetL.get((i + 1) % size);
    stroke(0);
    line(b.x, b.y, e.x, e.y); 
  }
}

void keyPressed() {
  if (key == 'r') {
    createRandomPointSet();
  }
  
  if (key == 'u'){
    if (drawHullU) {
      drawHullU = false; 
    } else {
      drawHullU = true;
    }
  }
  
  if (key == 'l'){
    if (drawHullL) {
      drawHullL = false; 
    } else {
      drawHullL = true;
    }
  }
}

class SortByXCord implements Comparator<PVector> {
  //@Override
  public int compare(PVector p1, PVector p2) {
    if (p1.x < p2.x) {
      return -1;
    } else if (p1.x > p2.x) {
      return 1;
    }
    
    return 0; //<>// //<>//
  }
}