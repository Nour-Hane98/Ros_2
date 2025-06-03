from setuptools import find_packages, setup

package_name = 'Exo_5'

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
        'Exo5_cli = Exo_5.Exo5_cli:main',
        'Exo5_ser = Exo_5.Exo5_ser:main',
        ],
    },
)

