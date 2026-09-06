import React, { useState, useEffect } from 'react';
import Logo from '../../components/logo/Logo';
import FieldInput from '../../components/fieldInput/FieldInput'
import Button from '../../components/button/Button'
import { FetchPOST } from '../../services/fetch/Fetch';
import { useHistory } from "react-router-dom";

import './Connection.css';


const Register = () => {

    const [fieldsInfo, setFielsInfo] = useState({
        email: "",
        password: "",
        code: "",
        validation: false
    })
    const history = useHistory();

    useEffect(() => {
        if (!fieldsInfo.validation)
            return
        FetchPOST("/api/user/register", fieldsInfo, (json, status) => {
            setFielsInfo({ ...fieldsInfo, validation: false })
            if (status === 200) {
                localStorage.setItem("sessionCarePlant", json.bearer)
                console.log("OK", localStorage.getItem("sessionCarePlant"))
                history.push("/dashboard")
            }
        })
        // eslint-disable-next-line react-hooks/exhaustive-deps
    }, [fieldsInfo.validation]);

    return (
        <>
            <FieldInput
                disabled={fieldsInfo.validation}
                label="Email"
                placeholder="Your Email"
                value={fieldsInfo.email}
                onChange={(v) => setFielsInfo({ ...fieldsInfo, email: v })}
            />
            <FieldInput
                disabled={fieldsInfo.validation}
                label="Password"
                placeholder="Your Password"
                value={fieldsInfo.password}
                onChange={(v) => setFielsInfo({ ...fieldsInfo, password: v })}
            />
            <FieldInput
                disabled={fieldsInfo.validation}
                label="Code ID"
                placeholder="Your Device Code ID"
                value={fieldsInfo.code}
                onChange={(v) => setFielsInfo({ ...fieldsInfo, code: v })}
            />
            <Button
                disabled={fieldsInfo.validation}
                value="Register"
                onClick={() => setFielsInfo({ ...fieldsInfo, validation: true })}
            />
        </>
    );
};


const Login = () => {

    const [fieldsInfo, setFielsInfo] = useState({
        email: "",
        password: "",
        validation: false
    })
    const history = useHistory();

    useEffect(() => {
        if (!fieldsInfo.validation)
            return
        FetchPOST("/api/user/login", fieldsInfo, (json, status) => {
            setFielsInfo({ ...fieldsInfo, validation: false })
            if (status === 200) {
                localStorage.setItem("sessionCarePlant", json.bearer)
                console.log("OK", localStorage.getItem("sessionCarePlant"))
                history.push("/dashboard")
            }
        })
        // eslint-disable-next-line react-hooks/exhaustive-deps
    }, [fieldsInfo.validation]);

    useEffect(() => {
        if (!fieldsInfo.validation)
            return
            FetchPOST("/api/user/login", fieldsInfo, (json, status) => {
                setFielsInfo({ ...fieldsInfo, validation: false })
                if (status === 200) {
                    localStorage.setItem("sessionCarePlant", json.bearer)
                    console.log("OK", localStorage.getItem("sessionCarePlant"))
                    history.push("/dashboard")
                }
            })        // eslint-disable-next-line react-hooks/exhaustive-deps
    }, [fieldsInfo.validation]);

    return (
        <>
            <FieldInput
                disabled={fieldsInfo.validation}
                label="Email"
                placeholder="Your Email"
                value={fieldsInfo.email}
                onChange={(v) => setFielsInfo({ ...fieldsInfo, email: v })}
            />
            <FieldInput
                disabled={fieldsInfo.validation}
                label="Password"
                placeholder="Your Password"
                value={fieldsInfo.password}
                onChange={(v) => setFielsInfo({ ...fieldsInfo, password: v })}
            />
            <Button
                disabled={fieldsInfo.validation}
                value="Login"
                onClick={() => setFielsInfo({ ...fieldsInfo, validation: true })}
            />
        </>
    );
};

const Connection = () => {

    const [connection, setConnection] = useState("login")
    const history = useHistory();

    useEffect(() => {
        if (!localStorage.getItem("sessionCarePlant") || localStorage.getItem("sessionCarePlant") === "")
            return
        history.push("/dashboard")
        // eslint-disable-next-line react-hooks/exhaustive-deps
    }, []);

    return (
        <div className='ConnectionRoot'>
            <div className='ConnectionSection'>
                <Logo width="300px" className="icon" />
                {connection === "login" ?
                    <>
                        <h6 className='title'>Login</h6>
                        <Login />
                        <button
                            className='btnSwap'
                            onClick={() => setConnection("register")}
                        >
                            You don't have a account ?
                        </button>
                    </>
                    :
                    <>
                        <h6 className='title'>Register</h6>
                        <Register />
                        <button
                            className='btnSwap'
                            onClick={() => setConnection("login")}
                        >
                            You already have a account ?
                        </button>
                    </>
                }
            </div>
        </div>
    );
};

export default Connection;
