from setuptools import find_packages, setup

package_name = 'exo_7'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='nourhane',
    maintainer_email='nourhane@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
        'exo7_ser = exo_7.exo7_ser:main',
        'exo7_cli = exo_7.exo7_cli:main',
        ],
    },
)

