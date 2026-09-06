import React, { useContext, useState } from 'react';

import { ProSidebar, Menu, MenuItem, SidebarHeader, SidebarFooter, SidebarContent } from 'react-pro-sidebar';

import MenuIcon from '@material-ui/icons/Menu';
import SettingsIcon from '@material-ui/icons/Settings';
import CloseIcon from '@material-ui/icons/Close';
import PersonIcon from '@material-ui/icons/Person';
import DashboardOutlinedIcon from '@material-ui/icons/DashboardOutlined';
import AddIcon from '@material-ui/icons/Add';
import PowerSettingsNewIcon from '@material-ui/icons/PowerSettingsNew';

import useStyles from '../../../styles/AppBar';

import sidebarBg from '../../../resources/images/appBarBackground.jpg'
import DataContext from '../../../contexts/dataContext';
import 'react-pro-sidebar/dist/css/styles.css';


const AppBarDashboard = ({index, setIndex}) => {

    const classes = useStyles();

    const [isCollapse, setCollapsed] = useState(true);
    const [, dataDispatch] = useContext(DataContext);

    const DisconnectedButton = () => {
        dataDispatch({type: "CLEAR_DATASTATE"})
        document.cookie = "tokenDashboardEpi=; expires= Thu, 20 Aug 2045 20:20:20 UTC; SameSite=None; Secure"
        setIndex({index: 99, i: 0});
    };

    return (
        <div className={classes.root}>
            <ProSidebar
                collapsed={isCollapse}
                className={classes.sidebar}
                image={sidebarBg}>

                <SidebarHeader>
                     <Menu iconShape="circle">
                        { isCollapse ?
                            <MenuItem icon={<MenuIcon />} onClick={() => setCollapsed(false)}/>
                        :
                            <MenuItem
                                icon={<CloseIcon />}
                                onClick={() => setCollapsed(true)}
                                style={{
                                    textTransform: 'uppercase',
                                    fontWeight: 'bold',
                                    fontSize: 14,
                                    letterSpacing: '1px',
                                    textOverflow: 'ellipsis',
                                    whiteSpace: 'nowrap',
                                }}>Close</MenuItem>
                        }
                    </Menu>
                </SidebarHeader>

                <SidebarContent>
                    <Menu iconShape="circle">
                        <MenuItem onClick={() => setIndex({index: 0, i: index.i + 1})} icon={<DashboardOutlinedIcon />}>Dashboard</MenuItem>
                        <MenuItem onClick={() => setIndex({index: 1, i: index.i + 1})} icon={<PersonIcon />}>Profile</MenuItem>
                        <MenuItem onClick={() => setIndex({index: 2, i: index.i + 1})} icon={<AddIcon />}>Adding</MenuItem>
                        <MenuItem onClick={() => setIndex({index: 3, i: index.i + 1})} icon={<SettingsIcon />}>Settings</MenuItem>
                    </Menu>
                </SidebarContent>

                <SidebarFooter>
                    <Menu
                        iconShape="circle"
                        onClick={DisconnectedButton}>
                        <MenuItem icon={<PowerSettingsNewIcon />}>Disconnected</MenuItem>
                    </Menu>
                </SidebarFooter>

            </ProSidebar>
        </div>
    );
};

export default AppBarDashboard;