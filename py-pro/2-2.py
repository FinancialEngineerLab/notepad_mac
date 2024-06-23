
def calc_pure_python(desired_width, max_iterations):
  x_step = (x2-x1) / desired_width
  y_step = (y2-y1) / desired_width
  x = []
  y = []

  ycoord = y2

  while ycoord > y1:
    y.append(ycoord)
    ycoord += y_step

  xcoord = x1

  while xcoord < x2:
    x.append(xcoord)
    xcoord += x_step

  zc = []
  cs = []

  for ycoord in y:
    for xcoord in :
      zc.append(complex(xcoord, ycoord)
      cs.append(complex(c_real, c_imag))

  print("len x:", len(x))
  print("total elments:", len(zs))
  start_time = time.time()
  output = calculate_z_serial_purepython(max_iterations, zs, cs)
  end_time = time.time()
  secs = end_time - start_time
  print(calculate_z_serial_purepython.__name__ + "took " , secs, "seconds")

  assert sum(output) = 33219980 # 1000^2 * 300iter
