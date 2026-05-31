class Solution {
public:

    bool asteroidsDestroyed(int initialMass,
                            vector<int>& asteroidList) {

        // Process asteroids from smallest to largest
        sort(asteroidList.begin(), asteroidList.end());

        // Use long long to avoid overflow
        long long spaceshipMass = initialMass;

        for (int asteroidSize : asteroidList) {

            // Cannot destroy an asteroid larger than current mass
            if (spaceshipMass < asteroidSize) {
                return false;
            }

            // Destroy asteroid and gain its mass
            spaceshipMass += asteroidSize;
        }

        return true;
    }
};
