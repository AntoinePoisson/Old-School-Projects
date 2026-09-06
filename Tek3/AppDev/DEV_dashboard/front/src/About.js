import React, { useEffect, useState } from 'react';

import useStyles from './styles/About';


const About = () => {

    const classes = useStyles();

    const [text, setText] = useState("");
    const [loading, setLoading] = useState(true);

    useEffect(() => {
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
                } else {
                    setText(`${JSON.stringify(result.result, null, 4).replace(/ /g, '&nbsp;').replace(/(\n)/g, '<br>').replace(/\\"/g, '"')}`);
                    setLoading(false);
                }
            })
            .catch((error) => {
            });
    }, []);


    if (loading) {
        return (
            <div className={classes.root}>
            </div>
        );
    }


    return (
        <div className={classes.root}>
            <div dangerouslySetInnerHTML={{__html: text}} />
        </div>
    );
};

export default About;