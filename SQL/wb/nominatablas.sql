use nomina;

create table empleado (
idEmpleado int not null auto_increment,
dpiEmpleado varchar (60) not null,
nombreEmpleado varchar (60) not null,
edadEmpleado int not null,
direccionEmpleado varchar (60) not null,
sexoEmpleado varchar (20) not null,
nacimientoEmpleado varchar (20) not null,
nacionalidadEmpleado varchar (20) not null,
correoEmpleado varchar(60) not null,
telefonoEmpleado varchar(30) not null,
primary key (idEmpleado)
);

create table banco (
idBanco int not null auto_increment,
nombreBanco varchar(60) not null,
direccionBanco varchar(60) not null,
primary key(idBanco)
);

create table puesto (
idPuesto int not null auto_increment,
nombrePuesto varchar(60) not null,
departamento int not null,
salarioPuesto double not null,
descripcionPuesto varchar(200) not null,
horarioPuesto varchar(100) not null,
primary key(idPuesto),
foreign key (departamento) references departamento(idDepartamento)
);

create table departamento (
idDepartamento int not null auto_increment,
nombreDepartamento varchar(60) not null,
descripcionDepartamento varchar(200) not null,
telefononoDepartamento varchar(20) not null,
correoDepartamento varchar(60) not null,
puesto int not null,
primary key (idDepartamento),
foreign key (puesto) references puesto(idpuesto)
);

create table concepto (
idConcepto int not null auto_increment,
nombreConcepto varchar(60),
valorConcepto double not null,
primary key (idConcepto)
);