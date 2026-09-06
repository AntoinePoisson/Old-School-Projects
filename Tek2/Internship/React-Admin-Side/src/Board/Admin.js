import React from 'react';
import { Admin, Resource } from 'react-admin';
import jsonServerProvider from 'ra-data-json-server';
import UserList from './UserList'
import PostIcon from '@material-ui/icons/Book';
import UserIcon from '@material-ui/icons/Group';
import { PostList,  PostEdit, PostCreate } from './Post.js';
import Dashboard from './DashBoard';

const dataProvider = jsonServerProvider('http://jsonplaceholder.typicode.com');


const MyAdmin = () => (
    <Admin dashboard={Dashboard} dataProvider={dataProvider}>
        <Resource name="posts" list={PostList} edit={PostEdit} create={PostCreate} icon={PostIcon} />
        <Resource name="users" list={UserList} icon={UserIcon} />
    </Admin>
);


export default MyAdmin;