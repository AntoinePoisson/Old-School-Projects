import React, { useEffect, useState } from 'react';
import { BrowserRouter as Router, Switch, Route, Redirect } from "react-router-dom";

import AppBar from './AppBar';
import DashboardHome from './Home';
import DashboardProfile from './Profile';
import DashboardAdding from './Adding';
import DashboardSettings from './Settings';


import useStyles from '../../../styles/DashboardPage';


const routes = [
    {
        path: "/dashboard/home",
        exact: false,
        main: () => <DashboardHome />
    },
    {
        path: "/dashboard/profile",
        exact: true,
        main: () => <DashboardProfile />
    },
    {
        path: "/dashboard/adding",
        exact: true,
        main: () => <DashboardAdding />
    },
    {
        path: "/dashboard/settings",
        exact: true,
        main: () => <DashboardSettings />
    },
    {
        path: "/dashboard/nothings",
        exact: true,
        main: () => <div />
    }
];

const DashboardPage = () => {

    const classes = useStyles();

    const [seletedIndex, setIndex] = useState({index: 0, i: 0});
    const [lastIndex, setLastIndex] = useState(0);

    useEffect(() => {
        if (seletedIndex.index === 4) {
            setIndex({index: lastIndex, i: 0});
            setLastIndex(4);
            return;
        }
        if (lastIndex === seletedIndex.index) {
            setIndex({index: 4, i: 0});
        } else {
            setLastIndex(seletedIndex.index);
        }
    // eslint-disable-next-line react-hooks/exhaustive-deps
    }, [seletedIndex]);

    if (seletedIndex.index === 99)
        return ( <Redirect to="/login" /> );

    return (
        <div className={classes.root}>
            <Router>
                <AppBar index={seletedIndex} setIndex={(index) => setIndex(index)} />
                <Redirect to={routes[seletedIndex.index].path} />
                <Switch>
                    { routes.map((route, index) => (
                        <Route
                            key={index}
                            path={route.path}
                            exact={route.exact}
                            children={<route.main />}
                        />
                      ))
                    }
                </Switch>
            </Router>
        </div>
    );
};

export default DashboardPage;