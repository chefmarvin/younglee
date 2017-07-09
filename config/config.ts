import { Configs, Config } from './config.type';
import * as basic_en from '../info/basic.en';
import * as education_en from '../info/education.en';
import * as work_en from '../info/work.en';
import * as project_en from '../info/project.en';
import * as skills_en from '../info/skills.en';
import * as language_en from '../info/language.en';
import * as links_en from '../info/links.en';
import * as basic_ch from '../info/basic.ch';
import * as education_ch from '../info/education.ch';
import * as work_ch from '../info/work.ch';
import * as project_ch from '../info/project.ch';
import * as skills_ch from '../info/skills.ch';
import * as language_ch from '../info/language.ch';
import * as links_ch from '../info/links.ch';

const configs: Configs = {
    en: {
        name: "Young Lee",
        title: `* Young Lee's CV, press [Q] to exit, [↑→↓←] to navigate *`,
        remoteUrl: 'https://raw.githubusercontent.com/YoungLeeNENU/younglee/node-version/info/',
        items: [
            [''],
            ['Overview'],
            ['Education'],
            ['Work Experience'],
            ['Projects'],
            ['Skills'],
            ['Language'],
            ['Links']
        ],
        info: ['',
            basic_en.basic_en,
            education_en.education_en,
            work_en.work_en,
            project_en.project_en,
            skills_en.skills_en,
            language_en.language_en,
            links_en.links_en
        ]
    },
    ch: {
        name: "李旸",
        title: '* 李旸的简历，按 [Q] 退出，按 [↑→↓←] 导航 *',
        remoteUrl: 'https://raw.githubusercontent.com/YoungLeeNENU/younglee/node-version/info/',
        items: [
            [''],
            ['基本信息'],
            ['教育情况'],
            ['工作经历'],
            ['项目'],
            ['技能'],
            ['语言能力'],
            ['链接']
        ],
        info: ['',
            basic_ch.basic_ch,
            education_ch.education_ch,
            work_ch.work_ch,
            project_ch.project_ch,
            skills_ch.skills_ch,
            language_ch.language_ch,
            links_ch.links_ch
        ]
    }
};

export default configs;
