

### Difference Between `CMD` and `ENTRYPOINT`

Both `CMD` and `ENTRYPOINT` in Docker define the default command that a container will execute when it starts. However, they differ in their flexibility and intended use:

1. **CMD**:
   - **Purpose**: Sets the default command or parameters for an executable.
   - **Override Capability**: It can be overridden by providing different arguments in the `docker run` command.
   - **Syntax**:
     - `CMD ["executable", "param1", "param2"]` (exec form, preferred for Docker)
     - `CMD param1 param2` (shell form)
   - **When to Use**: Use `CMD` when you want to specify a default behavior but still allow flexibility for the user to override it easily. This is useful for interpreted languages where you may want to specify a default script to run but let the user override it by specifying another script or command.

   **Example**:
   ```Dockerfile
   CMD ["python", "app.py"]
   ```

2. **ENTRYPOINT**:
   - **Purpose**: Defines the main command to be run as the container’s entrypoint.
   - **Override Capability**: If set, the command defined by `ENTRYPOINT` cannot be easily overridden. However, you can pass arguments to it.
   - **Syntax**:
     - `ENTRYPOINT ["executable", "param1", "param2"]` (exec form, recommended for consistency)
   - **When to Use**: Use `ENTRYPOINT` when you want the container to run a specific, fixed command, regardless of what arguments are provided at runtime. This is especially useful for compiled languages or services where the application has one main binary or command that should always run.

   **Example**:
   ```Dockerfile
   ENTRYPOINT ["myapp"]
   ```

### Combining `ENTRYPOINT` and `CMD`

A common practice is to use `ENTRYPOINT` to specify the main executable and `CMD` to specify default parameters. This way, you get a fixed entrypoint but retain flexibility to modify its arguments.

**Example**:
```Dockerfile
ENTRYPOINT ["python"]
CMD ["app.py"]
```

With this setup:
- By default, the container will run `python app.py`.
- If you want to override it, you can simply pass another script or file, like `docker run myapp other_script.py`, which will run `python other_script.py`.

### Why Use `CMD` in the Python Example?

In the Python Flask example, we use `CMD` to provide a flexible default command. This lets us easily change which file runs by overriding it at runtime if needed, which can be useful in development or testing scenarios. 

For example:
```bash
docker run my-python-app some_other_script.py
```

This would run `some_other_script.py` instead of `app.py`, demonstrating how `CMD` allows runtime overrides. Using `ENTRYPOINT` instead would make this override less flexible, as it would "lock in" the main command.