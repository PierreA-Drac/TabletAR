#!/usr/bin/python3

# Imports
# ==============================================================================

# Qt.
from PyQt5.QtWidgets import *

# Code
# ==============================================================================

# Initialization.
app = QApplication([])
window = QWidget()

# Display.
layout = QVBoxLayout()
layout.addWidget(QPushButton('Top'))
layout.addWidget(QPushButton('Bottom'))
layout.addWidget(QTextEdit('Insert a research here'))

# Launch the application until user close it.
window.setLayout(layout)
window.show()
app.exec_()
