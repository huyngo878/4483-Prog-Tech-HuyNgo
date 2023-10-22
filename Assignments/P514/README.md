### The railroad problem

The approach i take is to use a stack.
iterate over the caoches in teh desired order
if the next coach and we need it move it over to track b
if the next coach is not available move the current coach to the stack until
the correct one is available
if the current top of the stack is the correct one we move it to track b
