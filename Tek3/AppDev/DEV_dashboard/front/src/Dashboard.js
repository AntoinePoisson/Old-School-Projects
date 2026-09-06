import React, { useState, useEffect, useContext } from 'react';

import DashboardPage from './components/Displays/DashboardPage/MainComponent';

import { Redirect } from 'react-router-dom';
import { BallTriangle } from '@agney/react-loading';
import MySnackBar from './components/Tools/SnackBar';

import DataContext from './contexts/dataContext'


const Dashboard = () => {

    const [isLoading, setLoading] = useState(true);
    const [redirection, setRedirection] = useState(false);
    const [, dataDispatch] = useContext(DataContext);
    const [snackbar, setSnackbar] = useState({message: "", type: "", recall: 0})

    useEffect(() => {
        if (document.cookie.split('; ').find(row => row.startsWith('tokenDashboardEpi')) === undefined
            || document.cookie.split('; ').find(row => row.startsWith('tokenDashboardEpi')).split('=')[1] === undefined
            || document.cookie.split('; ').find(row => row.startsWith('tokenDashboardEpi')).split('=')[1].length === 0) {
            setRedirection(true);
            setSnackbar({ message: "Not Log", type: "info", recall: snackbar.recall + 1 });
            return;
        }
        let cookie = document.cookie
            .split('; ')
            .find(row => row.startsWith('tokenDashboardEpi'))
            .split('=')[1];
        const myInit_ = {
            method: "GET",
            headers: new Headers({ "Content-Type": "application/json" }),
            mode: "cors",
            cache: "default"
        };
        fetch(`http://localhost:8080/about/get`, myInit_)
            .then(async (res) => {
                const result = await res.json();
                if (result.error) {
                    setSnackbar({ message: "Failure Login", type: "error", recall: snackbar.recall + 1 });
                } else {
                    const myInit = {
                        method: "POST",
                        headers: new Headers({ "Content-Type": "application/json" }),
                        mode: "cors",
                        body: JSON.stringify({token : cookie}),
                        cache: "default"
                    };
                    fetch(`http://localhost:8080/token/get`, myInit)
                        .then(async (r) => {
                            const re = await r.json();
                            if (re.error) {
                                setSnackbar({ message: "Failure Login", type: "error", recall: snackbar.recall + 1 });
                            } else {
                                dataDispatch({ type: "SET_DATA", Token: cookie, About: result.result, TokenServices: re.result.tokens.length ? JSON.parse(re.result.tokens): [] });
                                setLoading(false);
                            }
                        })
                        .catch((error) => {
                            setSnackbar({ message: "Failure Login", type: "error", recall: snackbar.recall + 1 });
                        });
                }
            })
            .catch((error) => {
                setSnackbar({ message: "Failure Login", type: "error", recall: snackbar.recall + 1 });
            });
    // eslint-disable-next-line react-hooks/exhaustive-deps
    }, []);


    if (redirection === true) return ( <Redirect to="/login" /> );

    if (isLoading)
        return (
            <div style={{display: "flex", position: "relative", backgroundColor: "darkgray", justifyContent: "center"}}>
                <BallTriangle width={300} style={{color: "white"}} />
            </div>
        );

    return (
        <div>
            <DashboardPage />
            <MySnackBar message={snackbar.message} type={snackbar.type} recall={snackbar.recall} />
        </div>
    );
};

export default Dashboard;