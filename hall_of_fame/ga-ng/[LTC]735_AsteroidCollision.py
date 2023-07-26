class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        ## int -> size, sign -> direction
        ## smaller will be explode. same size? both explode
        ## same direction will never mmet

        stack = []

        for asteroid in asteroids:
            # print(f'aster: {asteroid}')
            
            if asteroid > 0:
                stack.append(asteroid)
            else:
                broken = False

                while not broken and stack:
                    # print(stack)
                    top = stack.pop()

                    if top * asteroid > 0:
                        stack.append(top)
                        break
                    else:
                        if abs(top) > abs(asteroid):
                            stack.append(top)
                            broken = True
                        elif abs(top) < abs(asteroid):
                            broken = False
                        else: ## both explode
                            broken = True

                if not broken:
                    stack.append(asteroid)


        return stack

