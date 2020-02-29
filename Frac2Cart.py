# Program to change Fractional Coordinates to Cartesian Coordinates for use
#use in moletemplate
# Using code from https://gist.github.com/Bismarrck/a68da01f19b39320f78a

import numpy as np

def get_fractional_to_cartesian_matrix(a, b, c, alpha, beta, gamma,
                                       angle_in_degrees=True):
    """
    Return the transformation matrix that converts fractional coordinates to
    cartesian coordinates.
    Parameters
    ----------
    a, b, c : float
        The lengths of the edges.
    alpha, gamma, beta : float
        The angles between the sides.
    angle_in_degrees : bool
        True if alpha, beta and gamma are expressed in degrees.
    Returns
    -------
    r : array_like
        The 3x3 rotation matrix. ``V_cart = np.dot(r, V_frac)``.
    """
    if angle_in_degrees:
        alpha = np.deg2rad(alpha)
        beta = np.deg2rad(beta)
        gamma = np.deg2rad(gamma)
    cosa = np.cos(alpha)
    sina = np.sin(alpha)
    cosb = np.cos(beta)
    sinb = np.sin(beta)
    cosg = np.cos(gamma)
    sing = np.sin(gamma)
    volume = 1.0 - cosa**2.0 - cosb**2.0 - cosg**2.0 + 2.0 * cosa * cosb * cosg
    volume = np.sqrt(volume)
    r = np.zeros((3, 3))
    r[0, 0] = a
    r[0, 1] = b * cosg
    r[0, 2] = c * cosb
    r[1, 1] = b * sing
    r[1, 2] = c * (cosa - cosb * cosg) / sing
    r[2, 2] = c * volume / sing
    return r


#Returning the matrix

matrix = get_fractional_to_cartesian_matrix(4.91317,4.9137,5.4047,90.00,90.000,120.000)
print("This is the translational matrix")
print("\n")
print(matrix)
print("\n")

#put frac coordinates in here

vector = [[0.1461],
          [0.7328],
          [0.8812]]


result = [[0],
          [0],
          [0]]

# iterating by row of translation matrix
for i in range(len(matrix)):

    # iterating by coloum by vector1.
    for j in range(len(vector[0])):

        # iterating by rows of vector
        for k in range(len(vector)):
            result[i][j] += matrix[i][k] * vector[k][j]

counter = 0
for r in result:
    if counter == 0:
        print("x = ")
    elif counter == 1:
        print("y = ")
    else:
        print("z = ")
    print(r)
    print("\n")
    counter += 1