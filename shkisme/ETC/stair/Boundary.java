package stair;

public class Boundary {

  private final int xPoint;
  private final int maxPoint;
  private final int minPoint;

  public Boundary(int xPoint, int maxPoint, int minPoint) {
    this.xPoint = xPoint;
    this.maxPoint = maxPoint;
    this.minPoint = minPoint;
  }

  public int getXpoint() {
    return xPoint;
  }

  public int getMaxPoint() {
    return maxPoint;
  }

  public int getMinPoint() {
    return minPoint;
  }
}
