import { Alert, Divider, Snackbar } from '@mui/material';
import React, { useEffect, useState } from 'react';
import Button from '../../components/button/Button';
import Select from 'react-select';
import useWindowDimensions from '../../services/window/Window';
import AppBar from './components/appbar/AppBar';
import BrushChart from './components/graphic/Graphic';
import FieldInput from '../../components/fieldInput/FieldInput';
import { FetchPOST } from '../../services/fetch/Fetch';
import { useHistory } from 'react-router-dom';
import { Triangle } from 'react-loader-spinner';

import './Dashboard.css';

const GraphicPage = () => {
    const { height, width } = useWindowDimensions();
    const [data, setData] = useState(undefined);
    const [plant, setPlant] = useState(undefined);
    const [snackBar, setSnackBar] = useState({ open: false, msg: "", already: "" });

    useEffect(() => {
        FetchPOST("/api/plant/get", { bearer: localStorage.getItem("sessionCarePlant") }, (json, status) => {
            if (status === 200) {
                setPlant({ name: json.plant, max: json.max, min: json.min })
                console.log("OK /api/plant/get")
            }
        })
        // eslint-disable-next-line react-hooks/exhaustive-deps
    }, []);

    useEffect(() => {
        const intervalId = setInterval(() => {
            FetchPOST("/api/data/get", { bearer: localStorage.getItem("sessionCarePlant") }, (json, status) => {
                if (status === 200) {
                    setData(json)
                    console.log("OK /api/data/get (data)", json)
                }
            })
        }, 1500 * 2) // in sec
        return () => clearInterval(intervalId)
        // eslint-disable-next-line react-hooks/exhaustive-deps
    }, []);

    useEffect(() => {
        if (!data || data.length === 0 || !plant || snackBar.open === true) {
            return;
        }
        var msg = ""
        if (data[0].close >= plant.max && snackBar.already !== "+") {
            msg = `Your Plant is too much Hydrate (current: ${data[0].close}%, limit: ${plant.max}%)`
            setSnackBar({ open: true, message: `Your Plant is too much Hydrate (current: ${data[0].close}%, limit: ${plant.max}%)`, already: "+" })
        }
        else if (data[0].close <= plant.min && snackBar.already !== "-") {
            msg = `You Need to Hydrate your Plant (current: ${data[0].close}%, limit: ${plant.min}%)`
            setSnackBar({ open: true, message: `You Need to Hydrate your Plant (current: ${data[0].close}%, limit: ${plant.min}%)`, already: "+" })
        }
        if (Notification.permission === "granted" && msg !== "") {
            new Notification("New message from CarePlant", {
                icon: "https://e7.pngegg.com/pngimages/139/668/png-clipart-leaf-plant-logo-root-plant-leaf-logo.png",
                body: msg
            })
        }
        else if (Notification.permission !== "denied" && msg !== "") {
            Notification.requestPermission((permission) => {
                if (permission === "granted") {
                    new Notification("New message from CarePlant", {
                        icon: "https://e7.pngegg.com/pngimages/139/668/png-clipart-leaf-plant-logo-root-plant-leaf-logo.png",
                        body: msg
                    })
                }
            })
        }
        // eslint-disable-next-line react-hooks/exhaustive-deps
    }, [data]);

    return (
        <div className='section'>
            <h6 className='title'>Plant Humidity{!plant ? "" : ` (${plant.name})`}:</h6>
            {!data ?
                <Triangle
                    height="400"
                    width="400"
                    color='green'
                    ariaLabel="triangle-loading"
                    wrapperStyle={{ marginLeft: "35%", height: "75vh", marginTop: "12%" }}
                    visible={true}
                />
                :
                <BrushChart className='graphic' width={width * 0.85} height={height * 0.75} data={data} />
            }
            <Snackbar open={snackBar.open} autoHideDuration={6000} onClose={() => setSnackBar({ ...snackBar, open: false })}>
                <Alert onClose={() => setSnackBar({ ...snackBar, open: false })} severity="warning" sx={{ width: '100%' }}>
                    {snackBar.message}
                </Alert>
            </Snackbar>
        </div>
    );
}

const PlantPage = () => {

    const [isLoading, setLoading] = useState(true);
    const [data, setData] = useState([]);
    const [value, setValue] = useState([]);
    const [fieldsInfo, setFielsInfo] = useState({
        name: "",
        max: 100,
        min: 0,
        validation: false
    })

    useEffect(() => {
        if (!isLoading) {
            return
        }
        FetchPOST("/api/plant/list", { bearer: localStorage.getItem("sessionCarePlant") }, (json, status) => {
            if (status === 200) {
                setData(json.map((e) => ({ ...e, value: e.name, label: e.name })))
                json.forEach(e => {
                    if (e.default) {
                        setValue({ ...e, value: e.name, label: e.name })
                    }
                });
                setLoading(false)
                console.log("OK /api/plant/list")
            }
        })
        // eslint-disable-next-line react-hooks/exhaustive-deps
    }, [isLoading]);

    useEffect(() => {
        if (isLoading || !value || value.length === 0 || !value.label) {
            return
        }
        FetchPOST("/api/plant/set", { bearer: localStorage.getItem("sessionCarePlant"), name: value.label }, (json, status) => {
            if (status === 200) {
                console.log("OK /api/plant/set")
            }
        })
        // eslint-disable-next-line react-hooks/exhaustive-deps
    }, [value]);

    useEffect(() => {
        if (isLoading || !fieldsInfo || fieldsInfo.name === "" || !fieldsInfo.validation) {
            return
        }
        FetchPOST("/api/plant/new", { bearer: localStorage.getItem("sessionCarePlant"), name: fieldsInfo.name, max: parseInt(fieldsInfo.max, 10), min: parseInt(fieldsInfo.min, 10) }, (json, status) => {
            if (status === 200) {
                console.log("OK /api/plant/new")
                setFielsInfo({
                    name: "",
                    max: 100,
                    min: 0,
                    validation: false
                })
                setLoading(true)
            }
        })
        // eslint-disable-next-line react-hooks/exhaustive-deps
    }, [fieldsInfo]);

    return (
        <div>
            <h6 className='title'>Plant Type:</h6>
            <div className='section2'>
                <div style={{ display: "block" }} className="select">
                    <Select
                        onChange={(e) => setValue(e)}
                        defaultValue={value}
                        value={value}
                        isLoading={isLoading}
                        isSearchable={true}
                        name="plant"
                        options={data}
                    />
                    <p style={{color: "black"}}>{`max: ${value.max}% et min: ${value.min}%`}</p>
                </div>
                <Divider className="divider" orientation="vertical" />
                <div className="add">
                    <h6 className='title2'>Create a New Plant:</h6>
                    <FieldInput label="Plant Type" placeholder="Plant Name" value={fieldsInfo.name} onChange={(e) => { setFielsInfo({ ...fieldsInfo, name: e }) }} />
                    <FieldInput label="Max Humidity" placeholder="Max Humidity" value={fieldsInfo.max} onChange={(e) => { setFielsInfo({ ...fieldsInfo, max: e }) }} />
                    <FieldInput label="Min Humidity" placeholder="Min Humidity" value={fieldsInfo.min} onChange={(e) => { setFielsInfo({ ...fieldsInfo, min: e }) }} />
                    <Button value="Submit" onClick={() => setFielsInfo({ ...fieldsInfo, validation: true })} />
                </div>
            </div>
        </div>
    );
}

const Dashboard = () => {

    const [anchorElNav, setAnchorElNav] = useState(null);
    const [anchorElUser, setAnchorElUser] = useState(null);
    const history = useHistory();

    useEffect(() => {
        if (localStorage.getItem("sessionCarePlant") && localStorage.getItem("sessionCarePlant") !== "")
            return
        history.push("/")
        // eslint-disable-next-line react-hooks/exhaustive-deps
    }, []);

    const handleSetNavMenu = (event) => {
        setAnchorElNav(event.currentTarget);
    };

    const handleOpenUserMenu = (event) => {
        setAnchorElUser(event.currentTarget);
    };
    const handleCloseUserMenu = () => {
        setAnchorElNav(null);
    };
    return (
        <div className="root">
            <AppBar anchorElUser={anchorElUser} handleSetNavMenu={handleSetNavMenu} handleOpenUserMenu={handleOpenUserMenu} handleCloseUserMenu={handleCloseUserMenu} />
            {anchorElNav && anchorElNav.innerText === "PLANT" ?
                <PlantPage />
                :
                <GraphicPage />
            }
        </div>
    );
};

export default Dashboard;
