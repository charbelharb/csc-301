-- Use any database, update connection string in main
-- Should create schema csc301 or update queries in
-- repositories

create schema csc301;

create table call
(
    id           serial,
    receiver     varchar(500) not null,
    caller       varchar(500) not null,
    duration     integer      not null,
    zone         integer,
    country_code varchar(10)
);

alter table call
    owner to postgres;

