
## decorator : faster !! ##
def timefn(fn):
    @wrap(fn)
    # arg: varaible arguments, kwarg: keywrod arguments
    def measure_time(*args, **kwargs):
        t1 = time.time()
        result = fn(*args, **kwargs)
        t2 = time.time()
        print(f"@timefn: {fn.__name__} took {t2-t1} seconds")
        return result
    return measure_time

@timefn
def calculate_z_serial_purepython(maxiter, zs,cs):
    ...



#timeit: focusing on CPU Calculation
'''python - m timeit -n 5 -r 1 -s "import julia1" ...'''

