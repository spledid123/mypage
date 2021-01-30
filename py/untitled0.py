# -*- coding: utf-8 -*-
"""
Created on Tue Jun 30 22:55:58 2020

@author: zsp
"""
import matplotlib.pyplot as plt

import numpy as np
def f(t):
    return np.exp(-t) * np.cos(2*np.pi*t)

a = np.array([0,0.2,0.3,0.4,0.5])

plt.subplot(2,1,1)
plt.plot(a, f(a))

plt.subplot(2,1,2)
plt.plot(a, np.cos(2*np.pi*a),'r--')
plt.show()
