class Solution:
    def asteroidsDestroyed(self,
                           initial_mass: int,
                           asteroid_list: List[int]) -> bool:

        # Process asteroids from smallest to largest
        asteroid_list.sort()

        # Current mass of the spaceship
        spaceship_mass = initial_mass

        for asteroid_size in asteroid_list:

            # Cannot destroy a larger asteroid
            if spaceship_mass < asteroid_size:
                return False

            # Gain the asteroid's mass after destroying it
            spaceship_mass += asteroid_size

        return True
